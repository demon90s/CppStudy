/*
 * 练习5.23：编写一段程序，从标准输入读取两个整数，输出第一个数除以第二个数的结果。
 */

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 0, b = 0;

	cout << "Enter two number(a/b): ";
	cin >> a >> b;
	cout << static_cast<double>(a) / b << endl;

	return 0;
}
