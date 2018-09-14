/* 字符小写转大写 */

#include <stdio.h>

char my_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 'a' + 'A';
	}

	return c;
}

int main()
{
	char c;

	c = 'h';
	c = my_toupper(c);

	printf("c = %c\n", c);

	return 0;
}
