/*
 * 下面这条 for 语句的输出是什么？
 *
 * for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
 * 	printf("%d ", i);
 */

/*
 * r1: i = 5, j = 4 -> 5
 * r2: i = 4, j = 3 -> 4
 * r3: i = 3, j = 2 -> 3
 * r4: i = 2, j = 1 -> 2
 * r5: i = 1, j = 0
 *
 * result: 5 4 3 2
 */

#include <stdio.h>

int main()
{
	int i, j;
	for (i = 5, j = i - 1; i > 0, j > 0; --i, j = i - 1)
		printf("%d ", i);

	return 0;
}
