/*
 * 扩展练习3中的程序使其可以处理三位数的反向。
 */

#include <stdio.h>

int main()
{
	int n;

	printf("Enter a three-digit number: " );
	scanf("%d", &n);

	printf("The reversal is: %d%d%d", n%100%10, n%100/10, n/100);

	return 0;
}
