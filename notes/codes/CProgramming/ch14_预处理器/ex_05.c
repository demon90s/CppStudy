/*
 * 下面的宏定义有问题：
 *
 * #define ABS(a) ((a)<0?-(a):a)
 *
 * 举例说明为什么 ABS 不能正常工作，并提出修改方法。你可以假定 ABS 的参数没有副作用。
 */

/*
 * PS，尚未找到不能工作的例子。
 */

#include <stdio.h>

#define ABS(a) ((a)<0?-(a):a)
#define ABS_FIX(a) ((a)<0?-(a):(a)) /* 应当给最后的一个a加上括号 */

int main()
{

	return 0;
}
