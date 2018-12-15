/*
 * 编写一个程序，接收用户录入的日期信息并且将其显示出来。其中，输入日期的形式为月/日/年（即
 * mm/dd/yy），输出日期的形式为年月日（即yymmdd）。格式如下所示：
 * Enter a date (mm/dd/yy): 2/17/96
 * You entered the date 960217
 */

#include <stdio.h>

int main()
{
	int yy, mm, dd;

	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d", &mm, &dd, &yy);

	printf("You entered the date %.2d%.2d%.2d\n", yy, mm, dd);

	return 0;
}
