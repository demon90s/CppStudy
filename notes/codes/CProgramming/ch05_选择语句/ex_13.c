/*
 * 如果i的值为17，那么下列语句显示的结果是什么？如果i的值为-17，那么下列语句显示的结果又是
 * 什么？
 *
 * printf("%d\n", i >= 0 ? i : -i);
 */

/*
 * 都是17
 */

#include <stdio.h>

int main()
{
	int i;

	i = 17;
	printf("%d\n", i >= 0 ? i : -i);

	i = -17;
	printf("%d\n", i >= 0 ? i : -i);

	return 0;
}
