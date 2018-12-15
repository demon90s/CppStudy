/*
 * 练习6.10：编写一个函数，使用指针形参交换两个整数的值。在代码中调用
 * 该函数并输出交换后的结果，以此验证函数的正确性。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int main()
{
	int a = 1, b = 2;
	swap(&a, &b);

	cout << a << " " << b << endl;

	return 0;
}
