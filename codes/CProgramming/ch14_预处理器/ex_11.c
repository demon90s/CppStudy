/*
 * (a) 指出下面的程序预处理后的形式。
 *
 * #define N 10
 *
 * void f(void);
 *
 * main()
 * {
 * 	f();
 * 	#ifdef N
 * 	#undef N
 * 	#endif
 * 	return 0;
 * }
 *
 * void f(void)
 * {
 * #if defined(N)
 * 	printf("N is %d\n", N);
 * #else
 * 	printf("N is undefined\n");
 * #endif
 * }
 *
 * (b) 这个程序的输出是什么？
 */

/*
 * 预处理后为：
 *
 * void f(void)
 * {
 * 	printf("N is undefined\n");
 * }
 *
 * 输出为：
 *
 * N is undefined
 */

#include <stdio.h>

#define N 10
void f(void);
int main()
{
	f();
	#ifdef N
	#undef N
	#endif
	return 0;
}

void f(void)
{
#if defined(N)
printf("N is %d\n", N);
#else
printf("N is undefined\n");
#endif
}
