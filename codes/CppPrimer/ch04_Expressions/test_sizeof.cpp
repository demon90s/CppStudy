/*
 * 测试一下sizeof
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void f()
{
}

int main()
{
	cout << sizeof f() << endl; 	// 返回的是1，然而会报warning

	return 0;
}
