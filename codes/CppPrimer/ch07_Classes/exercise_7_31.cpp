/*
 * 练习7.31：定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为
 * X的对象。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Y;

class X
{
	Y *p;
};

class Y
{
	X x;
};

int main()
{
	return 0;
}
