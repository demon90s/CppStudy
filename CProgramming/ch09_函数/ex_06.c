/*
 * 编写函数 digit(n, k) , 使得函数返回正整数n中第k个数字（从右边算起）。例如，digit(829, 1)
 * 返回9， digit(829, 2) 返回2，而 digit(829, 3) 则返回8。如果k大于n所含的数字的个数，那么
 * 函数返回-1。
 */

#include <stdio.h>

int digit(int n, int k)
{
	int i, tmp;

	i = 0;
	do {
		tmp = n % 10;
		n /= 10;

		i++;
		if (i == k) return tmp;
	
	} while (n != 0);

	return -1;
}

int main()
{
	int n, k;

	printf("Enter n k: ");
	scanf("%d%d", &n, &k);

	printf("%d", digit(n, k));

	return 0;
}
