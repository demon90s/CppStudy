/* Determins the length of a message */

#include <stdio.h>

// 把输入行的剩余字符读完，返回读入的字符数，不包括\n
int skips_rest_line()
{
	int length = 0;
	while (getchar() != '\n')
	{
		++ length;
	}

	return length;
}

int main()
{
	printf("Enter a message: ");
	int length = skips_rest_line();

	printf("Your message was %d character(s) long.\n", length);

	return 0;
}
