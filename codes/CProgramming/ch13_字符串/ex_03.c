/*
 假设按如下方式调用 scanf 函数：
 scanf("%d%s%d", &i, s, &j);
 如果用户输入12abc34 56def78，那么调用后i, s和j的值分别是多少？（假设i和j是int型变量，
 s是字符数组）
*/

/*
 i: 12
 s: abc34
 j: 56
*/

#include <stdio.h>

int main()
{
	int i, j;
	char s[10];

	scanf("%d%s%d", &i, s, &j);

	printf("i: %d\n", i);
	printf("s: %s\n", s);
	printf("j: %d\n", j);

	return 0;
}