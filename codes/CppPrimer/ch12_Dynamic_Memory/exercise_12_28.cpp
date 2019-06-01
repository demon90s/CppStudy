// 练习12.28：编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个
// 文件，并与用户交互来查询单词。使用vector、map和set容器来保存来自文件的数据并
// 生成查询结果

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	// 读入文件
	ifstream infile("../data/some_words.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return 1;
	}

	vector<string> lines;
	map<string, set<int>> word_to_line_map;

	// 存储数据
	{
		string line;
		size_t line_no = 0;

		while (getline(infile, line))
		{
			lines.push_back(line);

			istringstream iss(line);
			string word;

			while (iss >> word)
			{
				word_to_line_map[word].insert(line_no);
			}

			++line_no;
		}
	}

	// 与用户交互
	do
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q") break;

		// 查询
		if (word_to_line_map.find(s) != word_to_line_map.end())
		{
			cout << s << " occurs " << word_to_line_map[s].size() << " times" << endl;

			for (auto l : word_to_line_map[s])
			{
				cout << "(line " << l << ") " << lines[l] << endl;
			}
		}
		else
		{
			cout << "Cant find " << s << endl;
		}
	} while (true);

	return 0;
}
