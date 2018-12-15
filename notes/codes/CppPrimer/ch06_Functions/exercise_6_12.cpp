/*
 * 练习6.12：改写6.2.1节中练习6.10（第188页）的程序，使用引用而非
 * 指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？
 */

/*
 * 引用会好一点，少写了一些符号，看上去易于理解。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void swap(int &a, int &b)
{
	int tmp = b;
	b = a;
	a = tmp;
}

int main()
{
	int a = 1, b = 2;
	swap(a, b);

	cout << a << " " << b << endl;

	return 0;
}
