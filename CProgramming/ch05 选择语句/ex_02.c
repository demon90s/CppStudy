/*
 * 下列代码段对逻辑运算符进行了说明。假设i、j和k都是 int 型变量，请列出每道题中的输出结果。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	// (a) 1
	{
		i = 10; j = 5;
		printf("%d", !i < j);
	}
	putchar(10);

	// (b) 1
	{
		i = 2; j = 1;
		printf("%d", !!i + !j);
	}
	putchar(10);

	// (c) 1
	{
		i = 5; j = 0; k = -5;
		printf("%d", i && j || k);
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
