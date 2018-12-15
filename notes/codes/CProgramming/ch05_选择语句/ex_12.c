/*
 * 下列 if 语句在C语言中是否合法？
 * if (n == 1 - 10)
 *     printf("n is between 1 and 10\n");
 *
 * 如果合法，那么当n等于5时语句如何执行？
 */

/*
 * 合法，n等于5时不会进入 if 语句。这样的写法也是错误的。
 */

#include <stdio.h>

int main()
{
	int n;
	n = 5;

	if (n == 1 - 10)
		printf("n is between 1 and 10\n");

	return 0;
}
