// 练习10.29：编写程序，使用流迭代器读取一个文本文件，存入一个vector中的string里。

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main()
{
	fstream in("../data/some_words.txt");
	if (!in) {
		cerr << "open file fail" << endl;
		return 1;
	}

	istream_iterator<string> iter(in);
	istream_iterator<string> eof;

	vector<string> vec(iter, eof);

	for (const auto &w : vec)
		cout << w << " ";
	cout << endl;

	return 0;
}
