/*
 * 列出下列每段代码的输出结果。假设i、j和k都是 int 型变量。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	/*
	 * (a) 0 2
	 */
	{
		i = 1;
		printf("%d ", i++ - 1);
		printf("%d", i);
	}
	putchar(10);

	/*
	 * (b) 4 11 6
	 */
	{
		i = 10; j = 5;
		printf("%d ", i++ - ++j);
		printf("%d %d", i, j);
	}
	putchar(10);

	/*
	 * (c) 0 8 7
	 */
	{
		i = 7; j = 8;
		printf("%d ", i++ - --j);
		printf("%d %d", i, j);
	}
	putchar(10);

	/*
	 * (d) 3 4 5 4
	 */
	{
		i = 3; j = 4; k = 5;
		printf("%d ", i++ - j++ + --k);
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	return 0;
}
