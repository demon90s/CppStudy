// 练习13.13：理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类，
// 为该类定义这些成员，每个成员都打印出自己的名字
// 给X添加拷贝赋值运算符和析构函数，并编写一个程序以不同方式使用X的对象；
// 将它们作为非引用和引用参数传递；动态分配它们；将它们放于容器中；
// 诸如此类。观察程序的输出，直到你确认理解了什么时候会使用拷贝控制成员，
// 以及为什么会使用它们。当你观察程序输出时，记住编译器可以略过对拷贝构
// 造函数的调用。

#include <iostream>
#include <vector>

using namespace std;

struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()" << std::endl; }
};

void f1(X)
{
}

void f2(X&)
{
}

int main()
{
	//X x;
	//f1(x);
	//f2(x);
	//X x2;
	//x2 = x;
	
	//auto px = new X();
	//delete px;
	
	std::vector<X> x_vec;
	//x_vec.emplace_back();
	x_vec.push_back(X());

	return 0;
}
