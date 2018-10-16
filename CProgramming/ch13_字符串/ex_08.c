/*
 * 函数f如下所示：
 *
 * int f(char *s, char *t)
 * {
 * 	char *p1, *p2;
 *
 * 	for (p1 = s; *p1; p1++) {
 * 		for (p2 = t; *p2; p2++)
 * 			if (*p1 == *p2) break;
 * 		if (*p2 == '\0') break;
 * 	}
 * 	return p1 - s;
 * }
 *
 * (a) f("abcd", "babc") 的值是多少？
 * (b) f("abcd", "bcd") 的值是多少？
 * (c) 通常情况下，当传递两个字符串s和t时，函数的返回值是什么？
 */

/*
 * (a) 3
 * (b) 0
 * (c) 遍历s，对于当前的字符，如果不存在于t中，则返回这个字符所在的位置。
 */

#include <stdio.h>

int f(char *s, char *t)
{
	char *p1, *p2;
	for (p1 = s; *p1; p1++) {
		for (p2 = t; *p2; p2++)
			if (*p1 == *p2) break;
		if (*p2 == '\0') break;
	}
	return p1 - s;
}

int main()
{
	printf("%d\n", f("abcd", "babc"));
	printf("%d\n", f("abcd", "bcd"));

	return 0;
}
