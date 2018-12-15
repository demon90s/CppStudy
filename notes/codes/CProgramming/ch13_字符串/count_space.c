/*
 * 统计字符串中空格的数量
 */

#include <stdio.h>

int count_space(const char *s)
{
	int count = 0;
	for (; *s != '\0'; s++)
		if (*s == ' ')
			count++;
	return count;
}

int main()
{
	printf("space: %d\n", count_space("Hello World !!"));

	return 0;
}
