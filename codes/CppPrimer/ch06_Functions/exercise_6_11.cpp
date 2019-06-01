/*
 * 练习6.11：编写并验证你自己的reset函数，使其作用于引用类型的参数。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void reset(int &a)
{
	a = 0;
}

int main()
{
	int a = 42;
	reset(a);

	cout << a << endl;

	return 0;
}
