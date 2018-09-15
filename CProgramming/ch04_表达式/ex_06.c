/*
 * 列出下列每段代码的输出结果。假设i、j和k都是 int 型变量。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	/*
	 * (a) 63 8
	 */
	{
		i = 7; j = 8;
		i *= j + 1;
		printf("%d %d", i, j);
	}
	putchar(10);

	/*
	 * (b) 3 2 1
	 */
	{
		i = j = k = 1;
		i += j += k;
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	/*
	 * (c) 2 -1 3
	 */
	{
		i = 1; j = 2; k = 3;
		i -= j -= k;
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	/*
	 * (d) 0 0 0
	 */
	{
		i = 2; j = 1; k = 0;
		i *= j *= k;
		printf("%d %d %d", i, j, k);
	}
	putchar(10);

	return 0;
}
