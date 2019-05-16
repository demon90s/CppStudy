/*
 * strcat 函数：
 *
 * char *strcat(char *s1, const char *s2);
 *
 * strcat 函数把字符串 s2 的内容追加到字符串 s1 的末尾，并且返回字符串 s1。
 *
 * WARNING 如果 s1 指向的数组不是足够大到可以容纳 s2 指向的字符串中的字符，那么结果不可预测。
 */

/*
 * strncat 函数
 * 
 * char *strncat(char *s1, const char *s2, size_t n);
 * 
 * 和 strcat 基本一致，只不过最多复制 s2 中n个字符。
 * strncat 函数会保证其结果字符串始终以空字符结尾。
 * 
 */

#include <stdio.h>
#include <string.h>

void test_strcat()
{
	char str1[10];

	strcpy(str1, "abc");
	strcat(str1, "def");

	printf("str1: %s\n", str1);
}

void test_strncat()
{
	char str1[10];

	strcpy(str1, "abc");
	strncat(str1, "def", 2);

	printf("str1: %s\n", str1);
}

int main()
{
	test_strcat();
	test_strncat();

	return 0;
}
