/*
 * 编写函数 num_digits(n) , 使得函数返回正整数n中数字的个数。提示：为了确定n中的数字的个数，
 * 把这个数反复除以10.当n达到0时，除法的次数表明了n最初拥有的数字的个数。
 */

#include <stdio.h>

int num_digits(n)
{
	int cnt = 0;
	do {
		n /= 10;
		++cnt;
	} while (n != 0);

	return cnt;
}

int main()
{
	int n;
	printf("Enter num: ");
	scanf("%d", &n);

	printf("digits: %d\n", num_digits(n));

	return 0;
}
