/*
 * 下列代码段对关系运算符和判等运算符进行了说明。假设i、j和k都是 int 型变量，请列出每道题中
 * 的输出结果。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	// (a) 1
	{
		i = 2; j = 3;
		k = i * j == 6;
		printf("%d", k);
	}
	putchar(10);

	// (b) 1
	{
		i = 5; j = 10; k = 1;
		printf("%d", k > i < j);
	}
	putchar(10);

	// (c) 1
	{
		i = 3; j = 2; k = 1;
		printf("%d", i < j == j < k);
	}
	putchar(10);

	// (d) 1
	{
		i = 1; j = 2; k = 3;
		printf("%d", i < j || k);
	}
	putchar(10);

	return 0;
}
