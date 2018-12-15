/*
 * 编写函数gcd(m,n)用来计算整数m和n的最大公约数。（第6章的练习2描述了计算最大公约数的Euclid算法）
 */

/*
 * 编写程序，要求用户输入两个整数，然后计算并显示这两个整数的最大公约数（GCD）：
 * 
 * Enter two integers: 12 28
 * Greatest common divisor: 4
 *
 * 提示：求最大公约数的经典算法是 Euclid 算法，方法如下：分别让变量m和n存储两个数的值；用m除
 * 以n；把除数保存在m中，而把余数保存在n中；如果n为0，那么停止操作，m中的值是GCD；否则，
 * 从m除以n开始，重复上述除法过程。
 */

#include <stdio.h>

int gcd(int m, int n)
{
	int tmp;

	while (n != 0) {
		tmp = m;
		m = n;
		n = tmp % n;
	}

	return m;
}

int main()
{
	int m, n;

	printf("Enter two integers: ");
	scanf("%d%d", &m, &n);

	printf("Greatest common divisor: %d\n", gcd(m, n));

	return 0;
}
