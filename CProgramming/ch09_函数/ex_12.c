/*
 * 下面的（不要弄混）函数用来找到三个数的中间数。重新编写函数，使得它只有一条 return 语句。
 *
 * float median(float x, float y, float z)
 * {
 * 	if (x <= y)
 * 		if (y <= z) return y;
 * 		else if (x <= z) return z;
 * 		else return x;
 *
 * 	if (z <= y) return y;
 * 	if (x <= z) return x;
 * 	return z;
 * }
 */

#include <stdio.h>

float median(float x, float y, float z)
{
	float mid = z;

	if (x <= y)
		if (y <= z) mid = y;
		else if (x <= z) mid = z;
		else mid = x;
	else {
		if (z <= y) mid = y;
		if (x <= z) mid = x;
	}

	return mid;
}

int main()
{
	float x, y, z;
	printf("Enter 3 float: ");
	scanf("%f%f%f", &x, &y, &z);

	printf("median: %g\n", median(x, y, z));

	return 0;
}
