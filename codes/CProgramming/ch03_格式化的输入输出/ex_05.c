/*
 * 编写一个程序，对用户录入的产品信息进行格式化。程序运行后需有如下会话：
 * Enter item number: 583
 * Enter unit price: 13.5
 * Enter purchase date (mm/dd/yy): 10/24/95
 * Item    Unit    Purchase
 *         Price   Date
 * 583     $ 13.50 10/24/95
 *
 * 其中，数字项和日期项采用左对齐方式；单位价格采用右对齐方式。美元数量的最大取值为9999.99。
 * 提示：使用制表符控制列坐标。
 */

#include <stdio.h>

int main()
{
	int item_number;
	float unit_price;
	int mm, dd, yy;

	/* input */
	printf("Enter item number: ");
	scanf("%d", &item_number);

	printf("Enter unit price: ");
	scanf("%f", &unit_price);

	printf("Enter purchase date (mm/dd/yy): ");
	scanf("%d/%d/%d", &mm, &dd, &yy);

	/* output */
	printf("Item\tUnit\t\tPurchase\n");
	printf("\tPrice\t\tDate\n");
	printf("%-d\t$ %.2f\t\t%-d/%-d/%-d\n", item_number, unit_price, mm, dd, yy);
	

	return 0;
}
