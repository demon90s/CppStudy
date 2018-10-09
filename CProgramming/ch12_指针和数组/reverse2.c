/*
 * 程序：数列反向（改进版） 
 */

/* Reverses a series of numbers (pointer version) */

#include <stdio.h>

#define N 10

int main()
{
	int a[N], *p;

	printf("Enter %d numbers: ", N);
	for (p = a; p < a + N; p++)
		scanf("%d", p);

	printf("In reverse order:");
	for (p = a + N - 1; p >= a; p--)
		printf(" %d", *p);
	printf("\n");

	return 0;
}
