/*
 * 下面的 printf 函数调用产生的输出分别是什么？
 */

#include <stdio.h>

int main()
{
	// `代表空格

	// a: ````86,1040
	printf("%6d,%4d", 86, 1040);
	putchar('\n');

	// b: `3.02530e+01
	printf("%12.5e", 30.253);
	putchar('\n');

	// c: 83.1620
	printf("%.4f", 83.162);
	putchar('\n');

	// d: 1e-06
	printf("%-6.2g", .0000009979);
	putchar('\n');

	return 0;
}
