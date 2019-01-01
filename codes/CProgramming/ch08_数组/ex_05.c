/*
 * 修改程序 reverse.c ，利用表达式 sizeof(a) / sizeof(a[0]) （或者这个值的宏）来计算数组
 * 的长度。
 */

/*
 * 程序：数列反向（p100）
 *
 * Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31
 * In reverse order: 31 50 11 23 94 7 102 49 82 34
 */

/* Reverses a series of numbers */

#include <stdio.h>

#define N 10
#define ARR_LEN (sizeof(a) / sizeof(a[0]))

int main()
{
	int a[N], i;

	printf("Enter %lu numbers: ", ARR_LEN);
	for (i = 0; i < ARR_LEN; ++i)
		scanf("%d", &a[i]);

	printf("In reverse order:");
	for (i = ARR_LEN - 1; i >= 0; i--)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
