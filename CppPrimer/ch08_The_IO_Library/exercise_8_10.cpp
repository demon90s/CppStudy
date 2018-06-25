/*
 * 练习8.10：编写程序，将来自一个文件中的行保存在一个vector<string>中。然后
 * 使用一个istringstream从vector读取数据元素，每次读取一个单词。
 */

// ./exercise_8_10 < data/some_words.txt

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	vector<string> lines;
	string line;
	while (getline(cin, line))
		lines.push_back(line);

	string word;
	for (const auto &l : lines) {
		istringstream iss(l);
		while (iss >> word)
			cout << word << " ";

		cout << endl;
	}

	return 0;
}
