/*
 * strcmp 的实现
 */

#include <stdio.h>

int strcmp_(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

int main()
{
	printf("%d\n", strcmp_("Hello", "Hi"));
	printf("%d\n", strcmp_("Hi", "Hi"));
	printf("%d\n", strcmp_("Hi", "Hello"));

	return 0;
}
