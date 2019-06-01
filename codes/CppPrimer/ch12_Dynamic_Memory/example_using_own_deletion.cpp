// example: 使用我们自己的释放操作（p416）

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

// 删除器
void end_connection(connection *p)
{
	disconnect(*p);
}

void f(destination &d)
{
	// 获得一个连接；记住使用完后关闭它
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);

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
