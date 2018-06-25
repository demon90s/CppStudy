/*
 * 练习2.41：使用你自己的Sales_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的练习。眼下先把Sales_data类的定义和main函数放在同一个文件里。
 */

#include <iostream>
#include <string>

struct Sales_data
{
	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};
};

// 1.5.1节，1.20
// $ ./exercise_2_41 < data/book_sales
/*
int main()
{
	Sales_data sales_data;
	double price = 0.0;

	while (std::cin >> sales_data.bookNo >> sales_data.units_sold >> price) {
		sales_data.revenue = price * sales_data.units_sold;
		std::cout << sales_data.bookNo << " "
			  << sales_data.units_sold << " "
			  << sales_data.revenue << " "
			  << price 
			  << std::endl;
	}

	return 0;
}
*/

// 1.5.1节，1.21
// $ ./exercise_2_41 < data/add_item 

/*
int main()
{
	Sales_data sales_data1, sales_data2;
	double price = 0.0;

	std::cin >> sales_data1.bookNo >> sales_data1.units_sold >> price;
	sales_data1.revenue = price * sales_data1.units_sold;

	std::cin >> sales_data2.bookNo >> sales_data2.units_sold >> price;
	sales_data2.revenue = price * sales_data2.units_sold;

	if (!std::cin) {
		std::cerr << "Read Sales_data failed." << std::endl;
		return 1;
	}

	if (sales_data1.bookNo != sales_data2.bookNo) {
		std::cerr << "Data must refer to same ISBN." << std::endl;
		return 1;
	}

	Sales_data total;
	total.bookNo = sales_data1.bookNo;
	total.units_sold = sales_data1.units_sold + sales_data2.units_sold;
	total.revenue = sales_data1.revenue + sales_data2.revenue;

	double avg_price = 0.0;
	if (total.units_sold > 0)
		avg_price = total.revenue / total.units_sold;

	std::cout << total.bookNo << " "
		  << total.units_sold << " "
		  << total.revenue << " "
		  << avg_price << std::endl;

	return 0;
}
*/

// 1.5.1节，1.22
// ./exercise_2_41 < data/book_sales
/*
int main()
{
	Sales_data total;
	double price = 0.0;

	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;

		Sales_data trans;
		double trans_price = 0.0;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans_price) {
			trans.revenue = trans.units_sold * trans_price;

			if (trans.bookNo == total.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				double avg_price = 0.0;
				if (total.units_sold > 0)
					avg_price = total.revenue / total.units_sold;
				std::cout << total.bookNo << " "
					  << total.units_sold << " "
					  << total.revenue << " "
					  << avg_price << std::endl;

				total = trans;
			}
		}

		double avg_price = 0.0;
		if (total.units_sold > 0)
			avg_price = total.revenue / total.units_sold;
		std::cout << total.bookNo << " "
			  << total.units_sold << " "
			  << total.revenue << " "
			  << avg_price << std::endl;
	}

	return 0;
}
*/

// 1.5.2节，1.23
// $ ./exercise_2_41 < data/book_sales
/*
int main()
{
	Sales_data data;
	double price = 0.0;

	if (std::cin >> data.bookNo >> data.units_sold >> price) {
		data.revenue = price * data.units_sold;
		int cnt = 1;
		Sales_data tmp_data;
		double tmp_price = 0.0;

		while (std::cin >> tmp_data.bookNo >> tmp_data.units_sold >> tmp_price) {
			tmp_data.revenue = tmp_data.units_sold * tmp_price;
			if (tmp_data.bookNo == data.bookNo)
				++cnt;
			else {
				std::cout << data.bookNo << " has " << cnt << " transaction(s)" << std::endl;
				data = tmp_data;
				cnt = 1;
			}
		}
		std::cout << data.bookNo << " has " << cnt << " transaction(s)"; 
	}
	return 0;
}*/

// 1.6节，1.25
// $ ./exercise_2_41 < data/book_sales

int main()
{
	Sales_data total;
	double price = 0.0;

	if (std::cin >> total.bookNo >> total.units_sold >> price) {
		total.revenue = total.units_sold * price;
		Sales_data trans;
		double trans_price = 0.0;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans_price) {
			trans.revenue = trans.units_sold * trans_price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				double avg_price = 0.0;
				if (total.units_sold > 0) {
					avg_price = total.revenue / total.units_sold;
				}
				std::cout << total.bookNo  << " " << total.units_sold << " " << total.revenue << " " << avg_price << std::endl;
				total = trans;
			}
		}
		double avg_price = 0.0;
		if (total.units_sold > 0) {
			avg_price = total.revenue / total.units_sold;
		}
		std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue  << " " << avg_price  << std::endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}
