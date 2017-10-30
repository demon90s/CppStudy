/*
 * 练习7.7：使用这些新函数重写7.1.2节（第233页）练习中的交易处理程序。
 */

// ./exercise_7_07 < data/book_sales

// PS: 代码和exercise_7_06.cpp一模一样

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::string;

struct Sales_data
{
	Sales_data &combine(const Sales_data &rhs);
	std::string isbn() const { return bookNo; }

	std::string bookNo;
	unsigned int units_sold = {0};
	double revenue = {0.0};
};

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read(std::istream &is, Sales_data &sd)
{
	double price = 0.0;
	is >> sd.bookNo >> sd.units_sold >> price;
	sd.revenue = price * sd.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &sd)
{
	double avg_price = 0.0;
	if (sd.units_sold > 0)
		avg_price = sd.revenue / sd.units_sold;
	
	os << sd.bookNo << " "
	   << sd.units_sold << " "
	   << sd.revenue << " "
	   << avg_price;

	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data tmp = lhs;
	return tmp.combine(rhs);
}

int main()
{
	Sales_data total;	// 保存下一条交易记录的变量
	// 读入第一条交易记录，并确保有数据可以处理
	if (read(cin, total)) {
		Sales_data trans;	// 保存和的变量
		// 读入并处理剩余交易记录
		while (read(cin, trans)) {
			// 如果我们仍在处理相同的书
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;	// 输出结果
				total = trans;		// 处理下一本书
			}
		}
		print(cout, total) << endl;	// 输出最后一条交易
	}
	else {
		cerr << "No data?!" << endl;
	}

	return 0;
}
