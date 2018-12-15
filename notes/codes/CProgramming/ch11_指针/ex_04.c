/*
 * 编写下列函数：
 *
 * void swap(int *x, int *y);
 *
 * 当传递两个变量的地址时， swap 函数应该交换两者的值：
 *
 * swap(&x, &y);
 *
 * 利用此函数修改第9章中练习9的程序，使它可以完成这项工作。
 */

#include <stdio.h>

void swap(int *a, int *b);

int main()
{
	int x = 1, y = 2;

	swap(&x, &y);
	printf("x = %d, y = %d\n", x, y);

	return 0;
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
