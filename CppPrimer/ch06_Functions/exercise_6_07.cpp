/*
 * 练习6.7：编写一个函数，当它第一次调用时返回0，以后每次被调用返回值加1。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int foo()
{
	static int cnt = 0;
	return cnt++;
}

int main()
{
	cout << foo() << endl;
	cout << foo() << endl;
	cout << foo() << endl;

	return 0;
}
