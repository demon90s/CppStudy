/*
 * 请重新编写 fact 函数，使得编写后的函数不再递归。
 */

#include <stdio.h>

int fact(int n)
{
	int res = 1, i;

	for (i = 2; i <= n; i++) {
		res *= i;
	}

	return res;
}

int main()
{
	printf("fact(5): %d\n", fact(5));

	return 0;
}
