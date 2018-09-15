/*
 * 如果i和j都是正整数，是否(-i)/j的值和-(i/j)的值始终一样？验证你的答案。
 *
 * 一样。
 */

#include <stdio.h>

int main()
{
	int i, j;

	printf("Enter i: ");
	scanf("%d", &i);

	printf("Enter j: ");
	scanf("%d", &j);

	printf("(-i)/j: %d\n", (-i)/j);
	printf("-(i/j): %d\n", -(i/j));

	return 0;
}
