/*
 * 练习3.6：编写一段程序，使用范围for语句将字符串内的所有字符用X代替。
 */

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s("Hello World");
	cout << s << endl;

	for (auto &c : s)
		c = 'X';

	cout << s << endl;

	return 0;
}
