/* Computes pairwise average of three numbers. */

#include <stdio.h>

double average(double a, double b)
{
	return (a + b) / 2;
}

int main()
{
	double x, y, z;

	printf("Enter three numbers: ");
	scanf("%lf%lf%lf", &x, &y, &z);

	printf("average of %g and %g: %g\n", x, y, average(x, y));
	printf("average of %g and %g: %g\n", x, z, average(x, z));
	printf("average of %g and %g: %g\n", z, y, average(z, y));

	return 0;
}
