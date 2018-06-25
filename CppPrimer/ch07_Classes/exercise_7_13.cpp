/*
 * 练习7.13：使用istream构造函数重写第229页的程序。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

//--------------------------------------------------------------------------

struct Sales_data {
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		   bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	// 其他成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

	// 数据成员
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// 输入的交易信息包括ISBN、售出总数和售出价格
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

//--------------------------------------------------------------------------

int main()
{
	Sales_data total(cin);	// 保存下一条交易记录的变量
	// 读入第一条交易记录，并确保有数据可以处理
	if (cin) {
		// 读入并处理剩余交易记录
		while (true) {
			Sales_data trans(cin);	// 保存和的变量
			if (!cin) break;

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
