/*
 * 练习1.21：编写程序，读取两个ISBN相同的Sales_item对象，输出它们的和。
 */

/*
 * $ ./exercise_1_21 < data/add_item
 */

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item book1, book2;

	std::cin >> book1 >> book2;

	if (book1.isbn() != book2.isbn()) {
		std::cerr << "Data must refer to same ISBN." << std::endl;
		return 1;
	}

	std::cout << book1 + book2 << std::endl;

	return 0;
}
