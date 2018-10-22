/*
 * 编写一个宏 NELEMS(a) 来计算一个一维数组a中元素的个数。提示：使用 sizeof 运算符。
 */

#include <stdio.h>

#define NELEMS(a) ((int)(sizeof(a)/sizeof(a[0])))

int main()
{
	char str[] = "Hello World";

	printf("real len of str: %d\n", NELEMS(str));

	return 0;
}
