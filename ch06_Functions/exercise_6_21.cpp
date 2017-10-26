/*
 * 练习6.21：编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大
 * 的那个。在该函数中指针的类型应该是什么？
 */

// 应该是const int*，从而可以传入const对象的地址

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int compare(int a, const int *b)
{
	return a > *b ? a : *b;
}

int main()
{
	const int n = 10;
	cout << compare(5, &n) << endl;

	return 0;
}
