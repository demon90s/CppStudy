// 练习7.41：使用委托构造函数重新编写你的Sales_data类，给每个构造函数体添加
// 一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建Sales_data
// 对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::cerr;

//--------------------------------------------------------------------------

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
public:
	// 构造函数
	Sales_data(const std::string &s, unsigned n, double p) :
		   bookNo(s), units_sold(n), revenue(p*n)
	{
		cout << "Called constructor: " << "Sales_data(const std::string &s, unsigned n, double p)" << endl;
	}

	Sales_data() : Sales_data("", 0, 0.0)
	{
		cout << "Called constructor: " << "default" << endl;
	}

	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { }

	Sales_data(std::istream &is) : Sales_data()
	{
		//read(is, *this);  // 仅测试调用顺序，故屏蔽
		cout << "Called constructor: " << "Sales_data(std::istream &is)" << endl;
	}

	// 其他成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
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

inline
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
	//Sales_data sd1; 	// 调用顺序：三参数版本 -> 默认版本

	Sales_data sd2(cin);	// 调用顺序：三参数版本 -> 默认版本 -> istream参数版本

	return 0;
}
