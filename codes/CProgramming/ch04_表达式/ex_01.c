/*
 * 列出下列每段代码的输出结果。假设i、j和k都是 int 型变量。
 */

#include <stdio.h>

int main()
{
	int i, j, k;

	/*
	 * (a) 1 2
	 */
	{
		i = 5; j = 3;
		printf("%d %d", i / j, i % j);
	}
	putchar('\n');

	/*
	 * (b) 0
	 */
	{
		i = 2; j = 3;
		printf("%d", (i + 10) % j);
	}
	putchar('\n');

	/*
	 * (c) 1
	 */
	{
		i = 7; j = 8; k = 9;
		printf("%d", (i + 10) % k / j);
	}
	putchar('\n');

	/*
	 * (d) 0
	 */
	{
		i = 1; j = 2; k = 3;
		printf("%d", (i + 5) % (j + 2) / k);
	}
	putchar('\n');

	return 0;
}
