// example: 编写Basket类（容器与继承案例，p559）

#include <iostream>
#include <memory>
#include <set>

using namespace std;

class Quote
{
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

	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }

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

	Bulk_quote* clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote* clone() && override { return new Bulk_quote(std::move(*this)); }

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

class Basket
{
public:
	// Basket使用合成的默认构造函数和拷贝控制成员
	void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }

	void add_item(const Quote &sale)
	{ items.insert(std::shared_ptr<Quote>(sale.clone())); }

	void add_item(Quote &&sale)
	{ items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }

	// 打印每本书的总价和购物篮中所有书的总价
	double total_receipt(std::ostream&) const;

private:
	// 该函数用于比较shared_ptr, multiset成员会用到它
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); }

	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;	// 保存实时计算出的总价格
	// iter指向ISBN相同的一批元素中的第一个
	// upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		// 我们知道在当前的Basket中至少有一个关键字元素
		// 打印该书籍对应的项目
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl; // 打印最终的总价格
	return sum;
}

void func1()
{
	// 直接使用智能指针插入
	Basket bsk;
	bsk.add_item(make_shared<Quote>("0-201-70353-X", 10));
	bsk.add_item(make_shared<Bulk_quote>("0-201-70354-X", 10, 2, 0.5));
	bsk.add_item(make_shared<Bulk_quote>("0-201-70354-X", 10, 2, 0.5));

	bsk.total_receipt(cout);
}

void func2()
{
	// 使用拷贝/移动的版本插入
	Basket bsk;
	bsk.add_item(Quote("0-201-70353-X", 10));
	bsk.add_item(Bulk_quote("0-201-70354-X", 10, 2, 0.5));
	bsk.add_item(Bulk_quote("0-201-70354-X", 10, 2, 0.5));

	bsk.total_receipt(cout);
}

int main()
{
	//func1();
	func2();

	return 0;
}
