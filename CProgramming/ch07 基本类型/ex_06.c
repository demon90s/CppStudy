/*
 * 如果变量c是char类型，那么下列哪条语句是非法的？
 *
 * (a) i += c;
 * (b) c = 2 * c - 1;
 * (c) putchar(c);
 * (d) printf(c);
 */

#include <stdio.h>

int main()
{
	char c;
	int i;
	i = 0;
	c = 0;

	i += c;
	c = 2 * c - 1;
	putchar(c);
	/* printf(c); */

	return 0;
}
