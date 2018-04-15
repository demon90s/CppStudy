// example: 定义派生类（p529）

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

	virtual void debug() const
	{
		cout << "bookNo: " << bookNo << endl
		     << "price: " << price << endl;
	}

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
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

	void debug() const override
	{
		Quote::debug();
		cout << "min_qty: " << min_qty << endl
		     << "discount: " << discount << endl;
	}

private:
	std::size_t min_qty = 0;	// 适用折扣政策的最低购买量
	double discount = 0.0;		// 以小数表示的折扣额
};

// 练习15.11
void func1()
{
	Quote *quote = nullptr;
	Quote base("0-201-70353-X", 5);
	Bulk_quote derived("0-201-70353-X", 5, 5, 0.5);

	quote = &base;
	quote->debug();

	quote = &derived;
	quote->debug();
}

int main()
{
	func1();

	return 0;
}
