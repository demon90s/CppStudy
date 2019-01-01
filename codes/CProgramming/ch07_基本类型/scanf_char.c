/* 测试读入字符，且不要读入前面的空格 */

#include <stdio.h>

int main()
{
	char a, b;

	scanf("%c %c", &a, &b); // a和b之间可以输入任意个空格
	// scanf("%c%c", &a, &b); // 这样是不行的，b可以读取空格

	printf("%c, %c\n", a, b);

	return 0;
}
