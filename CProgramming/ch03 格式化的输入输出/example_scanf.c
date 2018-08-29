/*
 * scanf 案例，见 p26
 */

#include <stdio.h>

int main()
{
	int i, j;
	float x, y;
	
	scanf("%d%d%f%f", &i, &j, &x, &y);

	printf("i: %d\n", i);
	printf("j: %d\n", j);
	printf("x: %f\n", x);
	printf("y: %f\n", y);

	return 0;
}
