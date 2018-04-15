// 练习15.7：定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍
// 的数量不超过一个给定的限量时享受折扣，如果购买量一旦超过了限量，则超出的部分
// 将以原价销售。

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

class Bulk_quote : public Quote // Bulk继承自Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
	    : Quote(book, p), min_qty(qty), discount(disc) {}

	// 覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t cnt) const override
	{
		if (cnt <= min_qty)
			return cnt * (1 - discount) * price;
		else {
			auto nodiscount_cnt = cnt - min_qty;
			return nodiscount_cnt * price + (min_qty * (1 - discount) * price);
		}
	}

private:
	std::size_t min_qty = 0;	// 适用折扣政策的最低购买量
	double discount = 0.0;		// 以小数表示的折扣额
};

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os, const Quote &item, size_t n)
{
	// 根据传入item形参的对象类型调用Quote::net_price
	// 或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // 调用Quote::isbn
	   << " # sold: " << n << " total due: " << ret << endl;

	return ret;
}

int main()
{
	Quote base("0-201-70353-X", 10);
	Bulk_quote derived("0-201-70353-X", 10, 5, 0.5);

	print_total(cout, base, 10); // 100
	print_total(cout, derived, 10); // 5本享有折扣，75

	return 0;
}
