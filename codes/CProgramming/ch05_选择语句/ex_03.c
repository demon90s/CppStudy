/*
 * 下列代码对逻辑表达式的短路行为进行了说明。假设i、j和k都是 int 型变量，请列出每道题中的
 * 输出结果。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	// (a) 1
	{
		i = 3; j = 4; k = 5;
		printf("%d", i < j || ++j < k);
	}
	putchar(10);

	// (b) 07 8 9
	{
		i = 7; j = 8; k = 9;
		printf("%d", i - 7 && j ++ < k);
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	// (c) 18 8 9
	{
		i = 7; j = 8; k = 9;
		printf("%d", (i = j) || (j = k));
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	// (d) 12 1 1
	{
		i = 1; j = 1; k = 1;
		printf("%d", ++i || ++j && ++k);
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	return 0;
}
