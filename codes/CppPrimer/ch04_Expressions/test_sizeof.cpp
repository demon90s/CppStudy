/*
 * 测试一下sizeof
 * sizeof 是一个运算符，返回存储对象所需的字节数，该对象的类型可能是某个给定类型的名字，也可能由表达式的返回结果确定。
 * sizeof 在编译时进行计算。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void f()
{
}

int f2()
{

}

int main()
{
	//cout << sizeof f() << endl; 	// 返回的是1，然而会报warning

	cout << sizeof f2() << endl;	// 返回4

	return 0;
}
