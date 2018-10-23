/*
 * 假定 TOUPPER 定义成下面的宏：
 *
 * #define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))
 *
 * 假设s是一个字符串，i是一个 int 型变量。给出下面每个代码段所产生的输出。
 *
 * (a) strcpy(s, "abcd");
 * i = 0;
 * putchar(TOUPPER(s[++i]));
 *
 * (b) strcpy(s, "0123");
 * i = 0;
 * putchar(TOUPPER(s[++i]));
 */

/*
 * (a) D
 * (b) 2
 *
 * PS: 在参数列表里使用++，使得宏有副作用
 */

#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))

int main()
{
	int i;
	char s[20];

	/* a */
	strcpy(s, "abcd");
	i = 0;
	putchar(TOUPPER(s[++i]));

	/* b */
	strcpy(s, "0123");
	i = 0;
	putchar(TOUPPER(s[++i]));

	return 0;
}
