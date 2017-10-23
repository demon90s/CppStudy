/*
 * 练习6.5：编写一个函数输出其实参的绝对值
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int my_abs(int n)
{
	if (n > 0)
		return n;
	else
		return -n;
}

int main()
{
	cout << my_abs(1) << endl;
	cout << my_abs(-1) << endl;

	return 0;
}
