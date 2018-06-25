// 练习18.27：已知如上所示的继承体系，同时假定为MI添加了一个名为foo的函数：

/* 

(a) 列出在MI::foo中可见的所有名字。
    ival（全局），dval（全局），cval（形参），dval（局部），MI::ival，MI::dvec，Derived::sval, Derived::dval, Base1::ival, Base1::dval, Base1::cval, Base1::id（但不可访问），Base2::fval, Base2::dval, 所有print函数。

(b) 是否存在某个可见的名字是继承自多个基类的？
    有，比如dval。

(c) 将Base1的dval成员与Derived的dval成员求和后赋给dval的局部实例。

(d) 将MI::dvec的最后一个元素的值赋给Base2::fval。

(e) 将从Base1继承的cval赋给从Derived继承的sval的第一个字符。

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Base1 {
	void print(int) const {}

protected:
	int ival;
	double dval;
	char cval;

private:
	int *id;
};

struct Base2 {
	void print(double) const {}

protected:
	double fval;
	double dval;
};

struct Derived : public Base1 {
	void print(std::string) const {}
protected:
	std::string sval;
	double dval;
};

struct MI : public Derived, public Base2 {
	void print(std::vector<double>) {}

	void foo(double);

protected:
	int *ival;
	std::vector<double> dvec;
};

int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	(void)dval;

	// 练习中的问题发生在此处
	
	// (c)
	dval = Derived::dval + Derived::Base1::dval;

	// (d) 假定不是空容器
	fval = dvec.back();

	// (e) 假定不是空字符串
	Derived::sval[0] = Base1::cval; 
}

int main()
{

	return 0;
}
