/*
 * 利用13.6节的方法来精简 count_space 函数。特别是要用 while 循环替换for语句
 */

/*
 * 统计字符串中空格的数量
 */

#include <stdio.h>

int count_space(const char *s)
{
	int count = 0;
	while (*s)
		if (*s++ == ' ') count++;

	return count;
}

int main()
{
	printf("space: %d\n", count_space("Hello World !!"));

	return 0;
}
