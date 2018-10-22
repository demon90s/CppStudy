/*
 * 假定 DOUBLE 是如下宏：
 *
 * #define DOUBLE(x) 2*x
 *
 * (a) DOUBLE(1+2) 的值是多少？
 * (b) 4/DOUBLE(2) 的值是多少？
 * (c) 改正 DOUBLE 的定义
 */

/*
 * (a) 4
 * (b) 4
 */

#include <stdio.h>

#define DOUBLE(x) 2*x
#define DOUBLE_FIX(x) (2*(x))

int main()
{
	printf("%d\n", DOUBLE(1+2));
	printf("%d\n", 4/DOUBLE(2));

	printf("%d\n", DOUBLE_FIX(1+2));
	printf("%d\n", 4/DOUBLE_FIX(2));

	return 0;
}
