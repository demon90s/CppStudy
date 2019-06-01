/*
 * 练习3.8：分别用while循环和传统的for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？
 */

/*
 * for循环更好，因为循环变量写在内部，且用的是迭代形式。
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

	decltype(s.size()) index = 0;
	while (index != s.size())
		s[index++] = 'X';

	cout << s << endl;

	return 0;
}
