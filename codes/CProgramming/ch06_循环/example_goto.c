/*
 * goto 语句（p71）
 */

#include <stdio.h>

/* 输入一个值，判断它是否是质数 */
int main()
{
	int n;
	int d;

	printf("Enter a number: ");
	scanf("%d", &n);

	for (d = 2; d < n; ++d)
		if (n % d == 0) goto done;

done:
	if (d < n)
		printf("%d is divisible by %d\n", n, d);
	else
		printf("%d is prime\n", n);

	return 0;
}
