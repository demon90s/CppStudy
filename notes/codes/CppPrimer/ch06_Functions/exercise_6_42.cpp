/*
 * 练习6.42：给make_plural函数的第二个形参赋予默认实参's'，利用新版本的函数输出单词success和
 * failure的单数和复数形式。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 如果ctr的值大于1，返回word的复数形式
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
	return (ctr > 1) ? word + ending : word;
}

int main()
{
	cout << make_plural(1, "success", "es") << endl;
	cout << make_plural(2, "success", "es") << endl;

	cout << make_plural(1, "failure") << endl;
	cout << make_plural(2, "failure") << endl;

	return 0;
}
