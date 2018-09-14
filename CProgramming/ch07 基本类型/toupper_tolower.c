/* 测试这俩大小写转换的函数 */

#include <stdio.h>
#include <ctype.h>

int main()
{
	char c = 'a';
	
	c = toupper(c);
	printf("%c\n", c);

	c = tolower(c);
	printf("%c\n", c);

	return 0;
}
