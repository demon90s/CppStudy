// example: 派生类的拷贝控制成员（p554）

#include <iostream>

using namespace std;

class Quote {
public:
	Quote() { cout << "Quote::Quote()" << endl; }
	Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price)
	{ cout << "Quote::Quote(const std::string &book, double sales_price)" << endl; }

	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
	{ cout << "Quote::Quote(const Quote &q)" << endl; }

	Quote(Quote &&q) : bookNo(std::move(q.bookNo)), price(q.price)
	{ cout << "Quote::Quote(Quote &&q)" << endl; }

	Quote& operator=(const Quote &q)
	{
		bookNo = q.bookNo;
		price = q.price;
		cout << "Quote::operator=(const Quote &q)" << endl;
		return *this;
	}

	std::string isbn() const { return bookNo; }

	// 返回给定数量的书籍的销售额
	// 派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(std::size_t n) const
	{ return n * price; }

	virtual ~Quote()	// 对析构函数进行动态绑定
	{
		cout << "Quote::~Quote()" << endl;
	}

private:
	std::string bookNo;

protected:
	double price = 0.0;		// 代表普通状态下不打折的价格
};

class Bulk_quote : public Quote // Bulk继承自Quote
{
public:
	Bulk_quote() { cout << "Bulk_quote::Bulk_quote()" << endl; }
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
	    : Quote(book, p), min_qty(qty), discount(disc)
	{ cout << "Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)" << endl; }

	Bulk_quote(const Bulk_quote &bq) : Quote(bq), min_qty(bq.min_qty), discount(bq.discount)
	{ cout << "Bulk_quote::Bulk_quote(const Bulk_quote &bq)" << endl; }

	Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq)), min_qty(bq.min_qty), discount(bq.discount)
	{ cout << "Bulk_quote::Bulk_quote(Bulk_quote &&bq)" << endl; }

	Bulk_quote& operator=(const Bulk_quote &bq)
	{
		Quote::operator=(bq);
		min_qty = bq.min_qty;
		discount = bq.discount;
		cout << "Bulk_quote::operator=(const Bulk_quote &bq)" << endl;
		return *this;
	}

	~Bulk_quote()
	{
		cout << "Bulk_quote::Bulk_quote()" << endl;
	}

	// 覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t cnt) const override
	{
		if (cnt >= min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}

private:
	std::size_t min_qty = 0;	// 适用折扣政策的最低购买量
	double discount = 0.0;		// 以小数表示的折扣额
};

// 练习15.26
void func()
{
	cout << "1 ===>" << endl;
	Bulk_quote bq;	// 先调用基类的默认构造函数，然后调用派生类的

	cout << "2 ===>" << endl;
	Bulk_quote bq2("0-201-70353-X", 10, 5, .5); // 先调用基类的构造函数，然后调用派生类的

	cout << "3 ===>" << endl;
	Bulk_quote bq3(bq2);	// 先调用基类的拷贝构造函数，然后调用派生类的
	
	cout << "4 ===>" << endl;
	Bulk_quote bq4(std::move(bq2));	// 先调用基类的移动构造函数，然后调用派生类的

	cout << "5 ===>" << endl;
	bq4 = bq3;	// 先调用基类的赋值运算符，再调用派生类的

	cout << "6 Destructors calling ===>" << endl;
}

int main()
{
	func();

	return 0;
}
