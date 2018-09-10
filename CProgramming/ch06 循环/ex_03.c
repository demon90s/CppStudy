/*
 * 编写程序，要求用户输入一个分数，然后将其约分为最简分式：
 *
 * Enter a fraction: 6/12
 * In lowest terms: 1/2
 *
 * 提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数；然后分子和分母分别都除以
 * 最大公约数。
 */ 

#include <stdio.h>

int main()
{
	int m, n, tmp, gcd, divisor;

	printf("Enter a fraction: ");
	scanf("%d/%d", &m, &n);

	gcd = m;
	divisor = n;
	while (divisor != 0) {
		tmp = gcd;
		gcd = divisor;
		divisor = tmp % divisor;
	}

	printf("In lowest terms: %d/%d\n", m/gcd, n/gcd);

	return 0;
}
