/* Print a table of compound interest */

#include <stdio.h>

#define ARRAY_ITEM_COUNT(a) ((int)(sizeof(a) / sizeof(a[0])))
#define INITIAL_BALANCE 100.00

int main()
{
	int i, low_rate, num_years, year;
	double value[8];

	printf("Enter interest rate: ");
	scanf("%d", &low_rate);
	printf("Enter number of years: ");
	scanf("%d", &num_years);

	printf("\nYears");
	for (i = 0; i < ARRAY_ITEM_COUNT(value); ++i)
	{
		printf("%6d%%", low_rate + i);
		value[i] = INITIAL_BALANCE;
	}
	printf("\n");

	for (year = 1; year <= num_years; ++year)
	{
		printf("%3d     ", year);
		for (i = 0; i < ARRAY_ITEM_COUNT(value); ++i)
		{
			value[i] += (low_rate + i) / 100.0 * value[i];
			printf("%7.2f", value[i]);
		}
		printf("\n");
	}

	return 0;
}
