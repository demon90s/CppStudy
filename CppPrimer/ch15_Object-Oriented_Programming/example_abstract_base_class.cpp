// example: 抽象基类（p540）

#include <iostream>

using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }

	// 返回给定数量的书籍的销售额
	// 派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(std::size_t n) const
	{ return n * price; }

	virtual ~Quote() = default;	// 对析构函数进行动态绑定

private:
	std::string bookNo;

protected:
	double price = 0.0;		// 代表普通状态下不打折的价格
};

// 用于保存折扣值和购买量的类，派生类使用这些数据可以实现不同的价格策略
class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double p, std::size_t qty, double disc) :
		Quote(book, p), quantity(qty), discount(disc) {}

	double net_price(std::size_t) const = 0;

protected:
	std::size_t quantity = 0;		// 折扣适用的购买量
	double discount = 0.0;			// 表示折扣的小数值
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
	    : Disc_quote(book, p, qty, disc) {}

	// 覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t cnt) const override
	{
		if (cnt >= quantity)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
};

int main()
{
	//Disc_quote obj; // 练习15.17：cannot declare variable ‘obj’ to be of abstract type ‘Disc_quote’

	return 0;
}
