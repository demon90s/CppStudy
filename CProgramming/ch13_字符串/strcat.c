/*
 * strcat 实现
 */

#include <stdio.h>

char *strcat_(char *s1, const char *s2)
{
	char *p = s1;

	while (*p)
		p++;
	while ((*p++ = *s2++) != '\0');
	return s1;
}

int main()
{
	char str[20] = "Hello";

	printf("str: %s\n", strcat_(str, " World"));

	return 0;
}
