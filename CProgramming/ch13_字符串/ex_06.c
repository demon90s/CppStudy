/*
 * 编写名为 censor 的函数，用来把字符串中出现的每一处字母"foo"替换为"xxx"。例如，字符串
 * "food fool"会变为"xxxd xxxl"。在不失清晰性的前提下程序越短越好。
 */

#include <stdio.h>
#include <string.h>

char* censor(char *s)
{
	char* cursor;
	char* end;
	int i;

	cursor = s;
	end = s + strlen(s);

	while (cursor + 3 < end) {
		if (0 == strncmp(cursor, "foo", 3)) {
			for (i = 0; i < 3; i++)
				*cursor++ = 'x';
		}
		else
			cursor++;
	}

	return s;
}

int read_line(char str[], int n)
{
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';

	return i;
}

int main()
{
	char s[20];

	printf("Enter str: ");
	read_line(s, 20);


	printf("s: %s\n", censor(s));

	return 0;
}
