/*
 * 下列 if 语句在C语言中是否合法？
 *
 * if (n >= 1 <= 10)
 *     printf("n is between 1 and 10\n");
 *
 * 如果合法，那么当n等于0时语句如何执行？
 */

/*
 * 合法，n等于0时，会进入if内的语句。但这不是期望的。
 */

#include <stdio.h>

int main()
{
	int n;
	n = 0;

	if (n >= 1 <= 10)
		printf("n is between 1 and 10\n");

	return 0;
}
