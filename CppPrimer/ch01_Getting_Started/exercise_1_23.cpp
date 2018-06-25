/*
 * 练习1.23：编写程序，读取多条销售记录，并统计每个ISBN（每本书）有几条销售记录。
 */

/*
 * $ ./exercise_1_23 < data/book_sales
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item item;

	if (std::cin >> item) {
		int cnt = 1;
		Sales_item tmp_item;

		while (std::cin >> tmp_item) {
			if (tmp_item.isbn() == item.isbn())
				++cnt;
			else {
				std::cout << item.isbn() << " has " << cnt << " transaction(s)"
				          << std::endl;
				item = tmp_item;
				cnt = 1;
			}
		}
		std::cout << item.isbn() << " has " << cnt << " transaction(s)"
		          << std::endl;
	}

	return 0;
}
