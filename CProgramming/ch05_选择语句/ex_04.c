/*
 * 编写一个单独的表达式，要求这个表达式的值根据i是否小于、等于或大于j而分别为-1、0或+1。
 */ 

#include <stdio.h>

int main()
{
	int i, j, res;

	j = 10;

	printf("j = %d, Enter i: ", j);
	scanf("%d", &i);

	res = (i < j) ? -1 : (i == j ? 0 : 1);

	printf("res: %d\n", res);

	return 0;
}
