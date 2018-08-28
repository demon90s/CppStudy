/*
 * 编写一个程序，要求用户输入一个美金数量，然后显示出加了5%税率的相应金额。格式如下所示：
 * Enter a dollar amount: 100.00
 * With tax added: 105.00
 */

#include <stdio.h>

#define TAX_RATE 0.05

int main()
{
	float amount;

	printf("Enter a dollar amount: ");
	scanf("%f", &amount);

	printf("With tax added: %.2f\n", amount + amount * TAX_RATE);

	return 0;
}
