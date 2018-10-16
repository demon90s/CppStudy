/*
 按照下述要求分别实现 read_line 函数：

 (a) 在开始存储输入字符前跳过空白字符。
 (b) 在读入第一个空白字符时停止。提示：调用 isspace 函数来检查字符是否为空白字符。
 (c) 在读入第一个换行符时停止，然后把换行符存储到字符串中。
 (d) 把没有空间存储的字符留下以备后用
*/

#include <stdio.h>
#include <ctype.h>

#define LEN 20

int read_line(char str[], int n)
{
	char ch;
	int i = 0;

	while ((ch = getchar()) != '\n') {
		if (i == 0 && isspace(ch))
			continue;

		if (i != 0 && isspace(ch))
			break;

		if (i < n - 1)
			str[i++] = ch;
	}

	if (i < n - 1)
	{
		str[i++] = '\n';
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
	len = read_line(str, LEN);
	printf("read %d charactors: %s\n", len, str);

	return 0;
}
