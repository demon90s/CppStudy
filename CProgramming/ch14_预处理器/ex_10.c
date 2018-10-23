/*
 * 假定宏M有如下定义：
 * #define M 10
 *
 * 下面那项测试会失败？
 * (a) #if M
 * (b) #ifdef M
 * (c) #ifndef M
 * (d) #if defined(M)
 * (e) #if !defined(M)
 */

/*
 * (c) (e)
 */

#include <stdio.h>

#define M 10

int main()
{
	#if M
	printf("(a)\n");
	#endif

	#ifdef M
	printf("(b)\n");
	#endif

	#ifndef M
	printf("(c)\n");
	#endif

	#if defined(M)
	printf("(d)\n");
	#endif

	#if !defined(M)
	printf("(e)\n");
	#endif

	return 0;
}
