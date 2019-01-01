/*
 * 编写函数 day_of_year(month, day, year) , 使得函数返回某 month 某 day 是 year 这一年中的
 * 第几天（1和366之间的整数）。
 */

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Bool;

Bool is_leap_year(int year)
{
	if (0 != year % 100) return 0 == year % 4;

	return 0 == year % 400;
}

int day_of_year(int month, int day, int year)
{
	int days;
	int i;

	int month_days[12] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	if (is_leap_year(year)) month_days[1]++;

	days = 0;
	for (i = 0; i < month - 1; i++) {
		days += month_days[i];
	}

	days += day;

	return days;
}

int main()
{
	int month, day, year;
	
	printf("Enter month day year: ");
	scanf("%d%d%d", &month, &day, &year);

	printf("days: %d\n", day_of_year(month, day, year));

	return 0;
}
