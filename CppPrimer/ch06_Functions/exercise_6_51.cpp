/*
 * 练习6.51：编写函数f的4个版本，令其各输出一条可以区分的消息。验证上
 * 一个练习的答案，如果你回答错了，反复研究本节的内容直到你弄清自己错
 * 在何处。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void f()
{
	cout << "void f()" << endl;
}

void f(int)
{
	cout << "void f(int)" << endl;
}

void f(int, int)
{
	cout << "void f(int, int)" << endl;
}

void f(double, double = 3.14)
{
	cout << "void f(double, double = 3.14)" << endl;
}

int main()
{
	//f(2.56, 42);	// 二义性
	f(42);		// void f(int)
	f(42, 0);	// void f(int, int)
	f(2.56, 3.14);	// void f(double, double = 3.14)

	return 0;
}
