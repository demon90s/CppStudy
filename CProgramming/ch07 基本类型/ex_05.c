/*
 * 修改程序 sum2.c 以便可以进行一串 double 型值的求和计算。
 */

#include <stdio.h>

int main()
{
	double n, sum = 0;

	printf("This program sums a series of numbers.\n");
	printf("Enter numbers (0 to terminate): ");

	scanf("%lf", &n);
	while (n != 0) {
		sum += n;
		scanf("%lf", &n);
	}
	printf("The sum is: %f\n", sum);

	return 0;
}
