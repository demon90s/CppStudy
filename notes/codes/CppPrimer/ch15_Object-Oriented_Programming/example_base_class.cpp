// example: 定义基类（p528）

#include <iostream>
#include <string>

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

using namespace std;

int main()
{
	return 0;
}
