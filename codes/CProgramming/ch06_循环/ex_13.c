/*
 * 下面的程序段产生的输出是什么？
 *
 * sum = 0;
 * for (i = 0; i < 10; ++i) {
 * 	if (i % 2) continue;
 * 	sum += i;
 * }
 * printf("%d\n", sum);
 */

/*
 * 将10以内的所有偶数加起来的结果，2 + 4 + 6 + 8 = 20
 */

#include <stdio.h>

int main()
{
	int i, sum;

	sum = 0;
	for (i = 0; i < 10; ++i) {
		if (i % 2) continue;
		sum += i;
	}
	printf("%d\n", sum);

	return 0;
}
