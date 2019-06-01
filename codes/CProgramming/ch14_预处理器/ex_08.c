/*
 * 假定 GENERIC_MAX 是如下宏：
 *
 * #define GENERIC_MAX(type)\
 * type type##_max(type x, type y)\
 * {\
 * 	return x > y ? x : y;\
 * }
 *
 * (a) 写出 GENERIC_MAX(long) 被预处理器扩展后的形式
 * (b) 解释为什么 GENERIC_MAX 不能应用在像 unsigned long 这样的基本类型上？
 * (c) 如何使 GENERIC_MAX 对任何基本类型都可以正常工作？提示：不要改变 GENERIC_MAX 的定义。
 */

/*
 * (a)
 * long long_max(long x, long y)
 * {
 * 	return x > y ? x : y;
 * }
 *
 * (b) 因为 unsigned long 有一个空格，没办法用 ## 连接成一个合法的函数名
 *
 * (c) 可以使用类型别名，如下
 */

#include <stdio.h>

#define GENERIC_MAX(type)\
type type##_max(type x, type y)\
{\
	return x > y ? x : y;\
}

typedef unsigned long UIntLong;

GENERIC_MAX(UIntLong);

int main()
{
	printf("%ld\n", UIntLong_max(10, 42));

	return 0;
}
