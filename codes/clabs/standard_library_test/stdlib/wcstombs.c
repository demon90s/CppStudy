/*
 *	#include <stdlib.h>
 *	size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);
 *
 *	把宽字符串 pwcs 转换为多字节字符串 s 。 n 限制了存储到 s 中的字节的数量。
 *	当达到上限或者遇到空字符时，函数停止。
 *
 *	函数返回存储的字节的数量，但不会包含空字符。
 *	如果遇到一个宽字符无法对应任何多字节字符，函数返回-1 。
 */

#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");

	char s[100];
	wchar_t pwcs[] = L"你好啊";
	size_t n;

	memset(s, 0, sizeof(s));
	n = wcstombs(s, pwcs, 99);
	if (n > 0) {
		printf("translate %d bytes, str: %s\n", n, s);
	}

	return 0;
}
