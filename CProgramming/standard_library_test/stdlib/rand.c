/*
 * rand 函数
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int n;

	srand(time(0));

	n = rand() % 100;

	printf("rand n: %d\n", n);

	return 0;
}
