/*
 * 练习3.8：分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？
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

	for (decltype(s.size()) i = 0; i != s.size(); ++i)
		s[i] = 'X';

	cout << s << endl;

	return 0;
}
