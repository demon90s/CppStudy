/*
 * strlen 的实现
 */

#include <stdio.h>

size_t strlen(const char *s)
{
	const char *p = s;

	while (*s)
		s++;
	return s - p;
}

int main()
{
	char str[] = "Hello world";

	printf("len of str(%s) is: %lu\n", str, strlen(str));

	return 0;
}
