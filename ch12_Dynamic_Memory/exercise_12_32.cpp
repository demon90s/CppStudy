// 重写TextQuery和QueryResult类，用StrBlob代替vector<string>保存输入文件。

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

#include "./example_StrBlob/StrBlob.h"

using namespace std;

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);

public:
	QueryResult(const string &word) : m_lines(nullptr), m_line_numbers(nullptr), m_word(word) {}

	bool IsValid() const { return m_lines && m_line_numbers; }

	void SetRes(StrBlob *lines, set<int> *line_numbers)
	{
		m_lines = lines;
		m_line_numbers = line_numbers;
	}

private:
	StrBlob *m_lines;
	set<int> *m_line_numbers;
	string m_word;
};

class TextQuery
{
public:
	TextQuery(ifstream &ifs);

	QueryResult query(const string &word);

private:
	StrBlob m_lines;
	map<string, set<int>> m_word_to_line_map;
};

//------------------------------------------

// TextQuery implement

TextQuery::TextQuery(ifstream &ifs)
{
	string line;
	size_t line_no = 0;

	while (getline(ifs, line))
	{
		m_lines.push_back(line);

		istringstream iss(line);
		string word;

		while (iss >> word)
		{
			m_word_to_line_map[word].insert(line_no);
		}

		++line_no;
	}
}

QueryResult TextQuery::query(const string &word)
{
	QueryResult query_res(word);

	if (m_word_to_line_map.find(word) != m_word_to_line_map.end())
	{
		query_res.SetRes(&m_lines, &m_word_to_line_map[word]);
	}

	return query_res;
}

//------------------------------------------

ostream& print(ostream &os, const QueryResult &query_res)
{
	if (query_res.IsValid())
	{
		cout << query_res.m_word << " occurs " << query_res.m_line_numbers->size() << " times" << endl;

		for (auto line : *query_res.m_line_numbers)
		{
			cout << "(line " << line << ") " << (*query_res.m_lines)[line] << endl;
		}
	}
	else
	{
		cout << "Cant find " << query_res.m_word << endl;
	}

	return os;
}

void runQueries(ifstream &infile)
{
	// infile是一个ifstream，指向我们要处理的文件
	TextQuery tq(infile); // 保存文件并建立查询map

	// 与用户交互，提示用户输入要查询的单词，完成查询并打印结果
	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		// 若遇到了文件尾或用户输入了q时循环终止
		if (!(cin >> s) || s == "q") break;

		// 指向查询并打印结果
		print(cout, tq.query(s)) << endl;
	}
}

int main()
{
	ifstream infile("../data/some_words.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return 1;
	}

	runQueries(infile);

	return 0;
}
