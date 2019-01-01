// 练习12.15：重写第一题的程序，用lambda（参见10.3.2节，第346页）代替end_connection函数。

#include <iostream>
#include <memory>
#include <string>

using namespace std;

// 表示正在连接什么
struct destination
{
	std::string addr;
};

// 使用连接所需信息
struct connection
{
	std::string *addr;
};

// 打开连接
connection connect(destination *d)
{
	cout << "[DEBUG] connect: " << d->addr << endl;

	connection c;
	c.addr = new std::string(d->addr);

	return c;
}

// 关闭给定连接
void disconnect(connection c)
{
	cout << "[DEBUG] disconnect: " << *c.addr << endl;

	delete c.addr;
}

void f(destination &d)
{
	// 获得一个连接；记住使用完后关闭它
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) { disconnect(*p); } );

	// 使用连接，无需显示调用disconnect，智能指针会调用
	cout << "[DEBUG] using connection: " << *p->addr << endl;
}

int main()
{
	destination d;
	d.addr = "mysql";

	f(d);

	return 0;
}
