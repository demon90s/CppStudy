/*
 * strlen 函数：
 *
 * size_t strlen(const char *s);
 *
 * size_t 是无符号整数类型（通常是 unsigned int 或 unsigned long int）。
 *
 * strlen 函数返回字符串 s 的长度。更精确的说， strlen 函数返回s中第一个空字符前的字符的个数，但不包括空字符。
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "Hello world";
	int len;

	len = strlen(str);

	printf("len of str(%s) is: %u\n", str, len);

	return 0;
}
