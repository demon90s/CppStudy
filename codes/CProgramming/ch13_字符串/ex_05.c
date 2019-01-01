/*
 * (a) 编写名为 strcap 的函数用来把参数中的字母都改为大写字母。参数是空字符结尾的字符串，且此
 * 字符串包含任意的 ASCII 字符。使用数组下标的方式访问字符串中的字符。提示：使用 toupper 函数
 * 把每个字符转换成大写。
 *
 * (b) 重写 strcap 函数，这次使用指针来访问字符串中的字符。
 */

#include <stdio.h>
#include <ctype.h>

char* strcap_a(char *s)
{
	int i = 0;
	while (s[i]) {
		if (isalpha(s[i]))
			s[i] = toupper(s[i]);

		i++;
	}

	return s;
}

char* strcap_b(char *s)
{
	char *p = s;
	while (*p) {
		if (isalpha(*p))
			*p = toupper(*p);
		p++;
	}
	return s;
}

int main()
{
	char s[] = "Hello World";

	//printf("to upper: %s\n", strcap_a(s));
	printf("to upper: %s\n", strcap_b(s));

	return 0;
}
