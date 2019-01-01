// 练习17.38：扩展上一题中你的程序，将读入的每个单词打印到它所在的行。

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

int main()
{
	ifstream ifs("../data/some_words.txt");
	if (!ifs)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	map<string, set<size_t>> word_to_lines_map;

	size_t line = 1;
	char buffer[128] = {0};
	while (ifs.getline(buffer, sizeof(buffer), '\n')) // 如果buffer长度不够，并还未遇到分隔符，那么流会处于failbit状态
	{
		istringstream iss(buffer);
		string word;

		while (iss >> word)
			word_to_lines_map[word].insert(line);

		++line;
	}

	for (const auto &p : word_to_lines_map)
	{
		cout << setw(6) << p.first << ": " << setw(1);
		for (const auto &l : p.second)
		{
			cout << l << " ";
		}
		cout << endl;
	}

	return 0;
}
