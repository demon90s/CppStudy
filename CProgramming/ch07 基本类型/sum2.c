/*
 * 数列求和（改进版）（p81）
 */

/* Sums a series of numbers (using long int variabels) */

#include <stdio.h>

int main()
{
	long int n, sum = 0;

	printf("This program sums a series of integers.\n");
	printf("Enter integers (0 to terminate): ");

	scanf("%ld", &n);
	while (n != 0) {
		sum += n;
		scanf("%ld", &n);
	}
	printf("The sum is: %ld\n", sum);

	return 0;
}
