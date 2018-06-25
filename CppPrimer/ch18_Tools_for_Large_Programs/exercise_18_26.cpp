// 练习18.26：已知如上所示的继承体系，下面对print的调用为什么是错误的？适当
// 修改MI，令其对print的调用可以编译通过并正确执行。

// MI mi; mi.print(42);

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Base1 {
	void print(int) const {}
};

struct Base2 {
	void print(double) const {}
};

struct Derived : public Base1 {
	void print(std::string) const {}
};

struct MI : public Derived, public Base2 {
	void print(std::vector<double>) {}
};

int main()
{
	MI mi;
	//mi.print(42); // 非法，派生类的print函数隐藏了基类的，然而这个print函数不是可行函数
	

	// 可以明确指定要调用的版本
	mi.Base1::print(42);

	return 0;
}
