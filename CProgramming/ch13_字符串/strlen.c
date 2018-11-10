/*
 * strlen 的实现
 */

#include <stdio.h>

size_t strlen_(const char *s)
{
	const char *p = s;

	while (*s)
		s++;
	return s - p;
}

int main()
{
	char str[] = "Hello world";

	printf("len of str(%s) is: %d\n", str, (int)strlen_(str));

	return 0;
}
