// 练习9.49：如果一个字母延伸到中线之上，如d或f，则称其有上出头部分(ascender)。
// 如果一个字母延伸到中线之下，如p或q，则称其有下出头部分(descender)。编写程序，
// 读入一个单词文件，输出最长的即不包含上出头部分，也不包含下出头部分的单词。

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("./data/letter.txt");
	if (!in) {
		cerr << "file open failed" << endl;
		return -1;
	}

	string word;
	string longest_word;
	while (in >> word) {
		if (word.find_first_not_of("aceimnorsuvwxz") == string::npos && word.size() > longest_word.size())
			longest_word = word;
	}

	cout << longest_word << endl;

	return 0;
}
