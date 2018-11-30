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
 *  
 */

/*
 * strncpy 函数
 * 
 * char* strncpy(char *des, const char *src, size_t num);
 * 
 * 拷贝 num 个字符从 src 到 des ，如果在拷贝完 num 个字符前就已经遇到了 src 的空字符，那么就往 des 的后面继续添加0，
 * 直到拷贝满 num 个字符为止。如果拷贝够了 num 个字符且没有遇到空字符，那么不会在 des 的后面添加空字符。
 * 
 * 函数返回 des 。
 * 
 * des 和 src 不可以重叠。
 */

#include <stdio.h>
#include <string.h>

void test_strcpy()
{
	char str1[10];

	strcpy(str1, "abc");

	printf("str1: %s\n", str1);
}

void test_strncpy()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	/* copy to sized buffer (overflow safe) */
	strncpy(str2, str1, sizeof(str1));

	/* partial copy (only 5 chars) */
	strncpy(str3, str1, 5);
	str3[5] = '\0'; /* null character manually added */

	puts(str1);
	puts(str2);
	puts(str3);
}

int main()
{
	//test_strcpy();
	test_strncpy();
	return 0;
}
