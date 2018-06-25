// 练习18.25：假设我们有两个基类Base1和Base2，它们各自定义了一个名为print
// 的虚成员和一个虚析构函数。从这两个基类中我们派生出下面的类，它们都重新
// 定义了print函数。

// 通过下面的指针，指出在每个调用中分别使用了哪个函数。

#include <iostream>
#include <memory>

using namespace std;

class Base1
{
public:
	virtual ~Base1() { cout << "~Base1()" << endl; }
	virtual void print() = 0;
};

class Base2
{
public:
	virtual ~Base2() { cout << "~Base2()" << endl; }
	virtual void print() = 0;
};

class D1 : public Base1
{
public:
	~D1() { cout << "~D1()" << endl; }
	void print() override { cout << "D1::print" << endl; }
};

class D2 : public Base2
{
public:
	~D2() { cout << "~D2()" << endl; }
	void print() override { cout << "D2::print" << endl; }
};

class MI : public D1, public D2
{
public:
	~MI() { cout << "~MI()" << endl; }
	void print() override { cout << "MI::print" << endl; }
};

int main()
{
	Base1 *pb1 = new MI;
	Base2 *pb2 = new MI;
	D1 *pd1 = new MI;
	D2 *pd2 = new MI;

	// (a)
	pb1->print(); 	// MI::print

	// (b)
	pd1->print();	// MI::print

	// (c)
	pd2->print();	// MI::print

	// 析构的过程都一样

	// (d)
	cout << "d---------------------->\n";
	delete pb2;	// ~MI() -> ~D2() -> ~Base2() -> ~D1() -> ~Base1()
	cout << "<----------------------d\n";

	// (e)
	cout << "e---------------------->\n";
	delete pd1;	// ~MI() -> ~D2() -> ~Base2() -> ~D1() -> ~Base1()
	cout << "<----------------------e\n";

	// (df)
	cout << "f---------------------->\n";
	delete pd2;	// ~MI() -> ~D2() -> ~Base2() -> ~D1() -> ~Base1()
	cout << "<----------------------f\n";

	return 0;
}
