/*
 * 练习3.10：编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	string s;
	cout << "Enter a string with punctuation(s):" << endl;
	cin >> s;

	for (auto c : s)
		if (!ispunct(c))
			cout << c;
	cout << endl;

	return 0;
}
