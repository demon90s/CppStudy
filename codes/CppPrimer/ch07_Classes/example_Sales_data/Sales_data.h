#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>
#include "exceptions.h"

//--------------------------------------------------------------------------------

// 类的定义

class Sales_data {
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
	friend struct std::hash<Sales_data>;	
	
	// 重载的运算符（练习14.2, p493）
	friend std::istream& operator>>(std::istream &is, Sales_data &sd);
	friend std::ostream& operator<<(std::ostream &os, const Sales_data &sd);
	friend Sales_data operator+(const Sales_data &sd1, const Sales_data &sd2);
	friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
	friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

public:
	// 构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :
		   bookNo(s), units_sold(n), revenue(p*n) { }
	Sales_data(std::istream &);

	Sales_data& operator=(const std::string &s);
	Sales_data& operator+=(const Sales_data &rhs);

	// 其他成员函数
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	// 类型转换运算符（练习14.45）
	explicit operator std::string() const { 
		return isbn() + " " + std::to_string(units_sold) + " " + std::to_string(revenue) + " " + std::to_string(avg_price());
	}

	explicit operator double() const { return revenue; }

	static const std::string Sales_data::*pbookNo() { return &Sales_data::bookNo; } // 提供给练习19.13

	bool AvgPriceMoreThan(double price) const { return avg_price() > price; }

private:
	double avg_price() const;

	// 成员函数类型别名，练习19.16
	using AvgPrice = double (Sales_data::*)() const;

	// 数据成员
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

//--------------------------------------------------------------------------------

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

//--------------------------------------------------------------------------------
// 类模板特例化（p626）

// 打开std命名空间，以便特例化std::hash
namespace std {

template <>
struct hash<Sales_data>
{
	// 用来散列一个无序容器的类型必须要定义下列类型
	typedef size_t result_type;
	typedef Sales_data argument_type; // 默认情况下，此类型需要==
	size_t operator()(const Sales_data& s) const;
};

inline
size_t hash<Sales_data>::operator()(const Sales_data& s) const
{
	return hash<string>()(s.bookNo) ^
		hash<unsigned>()(s.units_sold) ^
		hash<double>()(s.revenue);
}

}

//--------------------------------------------------------------------------------成员函数定义BEG

inline
double Sales_data::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

inline
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	if (isbn() != rhs.isbn())
		throw isbn_mismatch("wrong isbns", isbn(), rhs.isbn());

	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

// 输入的交易信息包括ISBN、售出总数和售出价格
inline
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

inline
Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

inline
std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

inline
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

inline
std::istream& operator>>(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

inline
std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

inline
Sales_data operator+(const Sales_data &sd1, const Sales_data &sd2)
{
	Sales_data sum = sd1;
	sum.combine(sd2);
	return sum;
}

inline
Sales_data& Sales_data::operator=(const std::string &s)
{
	*this = Sales_data(s);
	return *this;
}

inline
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	combine(rhs);
	return *this;
}

inline
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

inline
bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}

//--------------------------------------------------------------------------------成员函数定义END

#endif // SALES_DATA_H
