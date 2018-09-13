/*
 * 编写程序，要求显示出单月的日历。用户说明这个月的天数和本月起始日是星期几。
 *
 * Enter number of days in month: 31
 * Enter starting day of the week(1=Sun, 7=Sat): 3
 *
 *         1   2   3   4   5
 * 6   7   8   9   10  11  12
 * 13  14  15  16  17  18  19
 * 20  21  22  23  24  25  26
 * 27  28  29  30  31
 *
 * 提示：此程序不像看上去那么难。最重要的内容是 for 语句使用变量i从1计数到n，n是此月的天数，
 * 显示出i的每个值。在循环中，用 if 语句判定i是否是一个星期的最后一天，如果是，就显示一个换
 * 行符。
 */

#include <stdio.h>

int main()
{
	int days, starting_day, i, j;

	printf("Enter number of days in month: ");
	scanf("%d", &days);

	printf("Enter starting day of the week(1=Sun, 7=Sat): ");
	scanf("%d", &starting_day);

	printf("Sun\tMon\tTues\tWed\tThur\tFri\tSat\n");
	
	for (i = 1; i < starting_day; ++i)
		printf("\t");


	for (j = 1; j <= days; ++j, ++i) {
		printf("%d\t", j);

		if (i >= 7) {
			printf("\n");
			i = 0;
		}
	}

	printf("\n");

	return 0;
}
