/*
 * 练习1.22：编写程序，读取多个具有相同ISBN的销售记录，输出所有记录的和
 */

/*
 * Tip：和1.6节的事例程序一样
 *
 * $ ./exercise_1_22 < data/book_sales
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total;

	if (std::cin >> total) {
		Sales_item trans;

		while (std::cin >> trans) {
			if (trans.isbn() == total.isbn())
				total += trans;
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}

		std::cout << total << std::endl;
	}

	return 0;
}
