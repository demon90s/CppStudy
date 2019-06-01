/*
 * 练习7.2：曾在2.6.2的练习（第67页）中编写了一个Sales_data类，请向这个类
 * 添加combine和isbn成员。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

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

int main()
{
	return 0;
}
