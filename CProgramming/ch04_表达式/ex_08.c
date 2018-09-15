/*
 * 表达式++i和i++中只有一个是与表达式(i += 1)完全相同的，哪一个是呢？验证你的答案。
 *
 * ++i
 */

#include <stdio.h>

int main()
{
	int i;

	i = 1;
	printf("%d\n", i++);

	i = 1;
	printf("%d\n", ++i);

	i = 1;
	printf("%d\n", (i += 1));

	return 0;
}
