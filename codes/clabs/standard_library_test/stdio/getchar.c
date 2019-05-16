/*
 * getchar 函数（p86）
 * 每次调用 getchar 函数时，它会读入一个字符，并返回这个字符
 */

#include <stdio.h>

int main()
{
	int ch;
	ch = getchar();

	printf("%c\n", ch);

	return 0;
}
