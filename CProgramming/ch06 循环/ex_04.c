/*
 * 在5.2节的 broker.c 程序中添加循环以使用户可以输入多比交易，并且程序可以计算每次的佣金。程
 * 序在用户输入的交易额为0时终止。
 *
 * Enter value of trade: 30000
 * Commision: $166.00
 * Enter value of trade: 20000
 * Commision: $144.00
 * Enter value of trade: 0
 */

#include <stdio.h>

int main()
{
	float value, commision;

	printf("Enter value of trade: ");
	scanf("%f", &value);

	while (value != 0) {
		if (value < 2500)
			commision = 30.0f + 0.01 * 0.17 * value;
		else if (value < 6250)
			commision = 56.0f + 0.01 * 0.66 * value;
		else if (value < 20000)
			commision = 76.0f + 0.01 * 0.34 * value;
		else if (value < 50000)
			commision = 100 + 0.01 * 0.22 * value;
		else if (value < 500000)
			commision = 155 + 0.01 * 0.11 * value;
		else
			commision = 255 + 0.01 * 0.09 * value;

		if (commision < 39)
			commision = 39;

		printf("The commision is: $%.2f\n", commision);

		printf("Enter value of trade: ");
		scanf("%f", &value);
	}

	return 0;
}
