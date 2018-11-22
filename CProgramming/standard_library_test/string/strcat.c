/*
 * strcat 函数：
 *
 * char *strcat(char *s1, const char *s2);
 *
 * strcat 函数把字符串 s2 的内容追加到字符串 s1 的末尾，并且返回字符串 s1。
 *
 * WARNING 如果 s1 指向的数组不是足够大到可以容纳 s2 指向的字符串中的字符，那么结果不可预测。
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[10];

	strcpy(str1, "abc");
	strcat(str1, "def");

	printf("str1: %s\n", str1);

	return 0;
}
