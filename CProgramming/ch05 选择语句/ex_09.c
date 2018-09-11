/*
 * 在美国的某个州，未婚居民需要负担下列所得税：
 *
 *     收入                   税金
 *     未超过750美元          收入的1%
 *     750~2250美元           7.50美元加上超出750美元部分的2%
 *     2250~3750美元          37.50美元加上超出2250美元部分的3%
 *     3750~5250美元          82.50美元加上超出3750美元部分的4%
 *     5250~7000美元          142.50美元加上超出5250美元部分的5%
 *     超过7000美元           230.00美元加上超出7000美元部分的6%
 *
 *     编写一个程序，要求用户输入需纳税的收入，然后显示税金。
 */

#include <stdio.h>

#define PER 0.01

int main()
{
	float income, tax;

	printf("Enter income: ");
	scanf("%f", &income);

	if (income <= 750)
		tax = income * 1 * PER;
	else if (income > 750 && income <= 2250)
		tax = 7.50 + (income - 750) * 2 * PER;
	else if (income > 2250 && income <= 3750)
		tax = 37.50 + (income - 2250) * 3 * PER;
	else if (income > 3750 && income <= 5250)
		tax = 82.50 + (income - 3750) * 4 * PER;
	else if (income > 5250 && income <= 7000)
		tax = 142.50 + (income - 5250) * 5 * PER;
	else
		tax = 230.00 + (income - 7000) * 6 * PER;

	printf("tax: %.2f\n", tax);

	return 0;
}
