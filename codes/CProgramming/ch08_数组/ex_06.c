/*
 * 修改程序 interest.c ，使得修改后的程序可以每月整合一次利息，而不再是每年整合一次利息。程
 * 序的输出格式不变；余额应该始终按每年一次的间隔显示。
 */

/* Print a table of compound interest */

#include <stdio.h>

#define ARRAY_ITEM_COUNT(a) ((int)(sizeof(a) / sizeof(a[0])))
#define INITIAL_BALANCE 100.00

int main()
{
	int i, low_rate, num_years, year, month;
	double value[8];

	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);

	printf("\nYears");
	for (i = 0; i < ARRAY_ITEM_COUNT(value); ++i)
	{
		printf("\t%d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (year = 1; year <= num_years; ++year)
	{
		printf("%d", year);
		for (i = 0; i < ARRAY_ITEM_COUNT(value); ++i)
		{
			for (month = 1; month <= 12; ++month) {
				value[i] += (low_rate + i) / 100.0 * value[i];
			}
			
			printf("\t%.2f", value[i]);
		}
		printf("\n");
	}

	return 0;
}
