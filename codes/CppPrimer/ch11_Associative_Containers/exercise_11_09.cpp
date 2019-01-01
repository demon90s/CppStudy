// 练习11.9：定义一个map，将单词与一个行号的list关联，list中保存的是单词所出现的行号。

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <sstream>

using namespace std;

using WordLine = map<string, list<int>>;

int main()
{
	WordLine word_line;
	string line;

	int line_no = 1;
	while (getline(cin, line))
	{
		istringstream iss(line);
		string word;

		while (iss >> word)
		{
			word_line[word].push_back(line_no);
		}

		++line_no;
	}

	for (const auto &pair : word_line)
	{
		cout << pair.first << ":";
		for (auto l : pair.second)
		{
			cout << " " << l;
		}
		cout << endl;
	}

	return 0;
}
