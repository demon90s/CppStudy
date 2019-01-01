/*
 * 读取一行字符串，返回读取的数量
 */

#include <stdio.h>

#define LEN 20

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
	char str[LEN + 1];
	int len;

	len = read_line(str, LEN);
	printf("read %d charactors: %s\n", len, str);

	return 0;
}
