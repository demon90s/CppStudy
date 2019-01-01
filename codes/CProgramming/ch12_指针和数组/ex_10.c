/*
 * 用指针的算术运算代替数组的下标来重新编写下列函数。（换句话说，消除变量i和所有用[]运算的
 * 地方。）改动尽可能少。
 *
 * int sum_array(int a[], int n)
 * {
 * 	int i, sum;
 *
 * 	sum = 0;
 * 	for (i = 0; i < n; i++)
 * 		sum += a[i];
 * 	return sum;
 * }
 */

#include <stdio.h>

int sum_array(int a[], int n)
{
	int *p, sum;

	for (p = a; p < a + n; p++)
		sum += *p;
	return sum;
}

int main()
{
	int a[4] = {1, 2, 3, 4};

	printf("sum: %d\n", sum_array(a, 4));

	return 0;
}
