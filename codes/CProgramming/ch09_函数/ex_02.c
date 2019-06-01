/*
 * 编写函数check(x, y, n)：如果x和y都落在0到n-1的闭区间内，那么使得函数check返回1。否则，
 * 函数应该返回0。假设x、y和n都是 int  类型。
 */

#include <stdio.h>

int check(int x, int y, int n)
{
	if (x >= 0 && x < n && y >= 0 && y < n) return 1;

	return 0;
}

int main()
{
	printf("%d\n", check(1, 2, 3));
	printf("%d\n", check(1, 2, 2));

	return 0;
}
