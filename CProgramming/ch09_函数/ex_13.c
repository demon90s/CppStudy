/*
 * 请采用精简 power 函数的方法，来简化 fact 函数。
 */

#include <stdio.h>

int fact(int n)
{
	return n <= 1 ? 1 : n * fact(n - 1);
}

int main()
{
	printf("fact(5): %d\n", fact(5));

	return 0;
}
