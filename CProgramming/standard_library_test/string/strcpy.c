/*
 * strcpy 函数：
 *
 * char* strcpy(char *s1, const char *s2);
 *
 * strcpy 函数把字符串 s2 复制给字符串 s1 ，也就是说， strcpy 函数把 s2 中的字符复制到 s1 中
 * 直到（并且包括）遇到 s2 中的一个空字符为止。
 *
 * strcpy 函数返回 s1 。
 *
 * WARNING 如果 s1 不足以存储 s2 ，那么结果不可预测。
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[10];

	strcpy(str1, "abc");

	printf("str1: %s\n", str1);

	return 0;
}
