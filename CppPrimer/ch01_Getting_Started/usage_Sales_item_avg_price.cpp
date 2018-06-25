// 1.6节书店程序，从一个文件中读取销售记录，生成每本书的销售报告，显示售出册数、总销售额和平均售价。我们假定每个ISBN书号的所有销售记录在文件中是聚在一起保存的。

// $ ./usage_Sales_item_avg_price < data/book_sales

#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item total; // variable to hold data for the next transaction

	// read the first transaction and ensure that there are data to process
	if (std::cin >> total) {
		Sales_item trans; // vairable to hold the running sum
		// read and process the remaining transactions
		while (std::cin >> trans) {
			// if we're still processing the same book
			if (total.isbn() == trans.isbn())
				total += trans; // update the running total
			else {
				// print results for the previous book
				std::cout << total << std::endl;
				total = trans; // total now refers to the next book
			}
		}
		std::cout << total << std::endl; // print the last transaction
	}
	else {
		// no input warn the user
		std::cerr << "No data?!" << std::endl;
		return -1;	// indicate failure
	}

	return 0;
}
