/*
 * 编写程序实现数字反向，即根据用户输入的两位数，反向显示出该数相应位上数字。要求程序执行过
 * 程中需要具有下列显示信息。
 *
 * Enter a two-degit number: 28
 * The reversal is: 82
 */

#include <stdio.h>

int main()
{
	int n;

	printf("Enter a two-digit number: ");
	scanf("%d", &n);

	printf("The reversal is: %d%d\n", n%10, n/10);

	return 0;
}
