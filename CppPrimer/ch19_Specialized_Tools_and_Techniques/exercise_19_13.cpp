// 练习19.13：定义一个类型，使其可以表示指向Sales_data类的bookNo成员的指针。

#include <iostream>
#include "../ch07_Classes/example_Sales_data/Sales_data.h"

int main()
{
	auto pbookNo = Sales_data::pbookNo();
	Sales_data sd("0-201-88954-4");

	std::cout << sd.*pbookNo << std::endl;

	return 0;
}
