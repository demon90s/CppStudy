/*
 * 显示如何用等价的 goto 语句替换 continue 语句。
 */

#include <stdio.h>

int main()
{
	/* 输出10以内的奇数 */
	int i;

	for (i = 0; i < 10; ++i) {
		if (i % 2 == 0) goto end_of_loop;

		printf("%d ", i);

		end_of_loop:;
	}

	return 0;
}
