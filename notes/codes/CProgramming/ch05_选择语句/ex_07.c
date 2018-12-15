/*
 * 同时采用下列两种变化对程序 borker.c 进行修改。
 *
 * （a）不再直接用交易额，而是要求用户输入股票的数量和每股的价格。
 * （b）增加语句用来计算经纪人竞争对手的佣金（少于2000股时佣金为每股33美元+3美分，2000股或更
 * 大股时佣金为每股33美元+2美分）。显示原有的经纪人的佣金的同时，显示竞争对手的佣金。
 */

#include <stdio.h>

int main()
{
	int stock_num;
	float stock_value, value, commision, competitor_commision;

	printf("Enter stock_num: ");
	scanf("%d", &stock_num);
	printf("Enter stock_value: ");
	scanf("%f", &stock_value);

	value = stock_num * stock_value;

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

	{
		/* calc for competitor commision */
		if (stock_num < 2000)
			competitor_commision = 33.03 * stock_num;
		else
			competitor_commision = 33.02 * stock_num;
	}

	printf("The commision is: $%.2f\n", commision);
	printf("The competition commision is: %.2f\n", competitor_commision);

	return 0;
}
