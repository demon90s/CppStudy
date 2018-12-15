/*
 * 程序：数列反向（p100）
 *
 * Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31
 * In reverse order: 31 50 11 23 94 7 102 49 82 34
 */

/* Reverses a series of numbers */

#include <stdio.h>

#define N 10

int main()
{
	int a[N], i;

	printf("Enter %d numbers: ", N);
	for (i = 0; i < N; ++i)
		scanf("%d", &a[i]);

	printf("In reverse order:");
	for (i = N - 1; i >= 0; i--)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
