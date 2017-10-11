/*
 * 练习3.7：就上一题完成的程序而言，如果将循环变量的类型设为char将发生什么？先估计一下结果，然后实际编程进行验证。
 */

/*
 * 没有区别。auto得到的类型就是char。
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

	for (char &c : s)
		c = 'X';

	cout << s << endl;

	return 0;
}
