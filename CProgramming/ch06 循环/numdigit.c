/* Calculates the number of digits in an integer */

#include <stdio.h>

int main()
{
	int digits = 0, n;

	printf("Enter a nonnegative integer: ");
	scanf("%d", &n);

	do
	{
		n /= 10;
		++digits;
	} while (n > 0);

	printf("The number has %d digit(s).\n", digits);

	return 0;
}
