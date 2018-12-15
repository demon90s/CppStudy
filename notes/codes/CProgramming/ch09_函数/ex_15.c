/*
 * 编写递归版本的 gcd 函数（参加练习3）。有一种用于计算 gcd(m, n) 的策略；如果 n 为0，那么返回m；
 * 否则，递归地调用 gcd 函数，把n作为第一个实际参数进行传递，而把 m % n 作为第二个实际参数进行传
 * 递。
 */

#include <stdio.h>

int gcd(int m, int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

int main()
{
	int m, n;

	printf("Enter two number: ");
	scanf("%d%d", &m, &n);

	printf("gcd: %d\n", gcd(m, n));

	return 0;
}
