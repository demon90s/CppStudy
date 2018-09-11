/*
 * 下面是蒲福风力的简单版本。蒲福风力等级是用于测量风力的。
 *
 *     速率（=海里/小时）    描述
 *     小于1                 Calm（无风）
 *     1~3                   Light air（轻风）
 *     4~27                  Breeze（微风）
 *     28~47                 Gale（大风）
 *     48~63                 Storm（暴风）
 *     大于63                Hurricane（飓风）
 *
 * 编写一个程序，要求用户输入风速（按照海里/小时），然后显示相应的描述。
 */

#include <stdio.h>

int main()
{
	int wind_speed;

	printf("Enter wind speed: ");
	scanf("%d", &wind_speed);

	if (wind_speed < 1)
		printf("Calm\n");
	else if (wind_speed >= 1 && wind_speed <= 3)
		printf("Light air\n");
	else if (wind_speed >= 4 && wind_speed <= 27)
		printf("Breeze\n");
	else if (wind_speed >= 28 && wind_speed <= 47)
		printf("Gale\n");
	else if (wind_speed >= 48 && wind_speed <= 63)
		printf("Storm\n");
	else if (wind_speed > 63)
		printf("Hurricane\n");

	return 0;
}
