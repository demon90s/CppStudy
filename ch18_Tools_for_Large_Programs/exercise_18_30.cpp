// 练习18.30：在Base中定义一个默认构造函数、一个拷贝构造函数和一个接受int形参的构造函数。在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的实参初始化其Base部分。

#include <iostream>
using namespace std;

class Class {
public:
	Class() { cout << "Class()" << endl; }
};

class Base : public Class {
public:
	Base() { cout << "Base()" << endl; }
	Base(const Base&) {}
	Base(int) {}
};

class D1 : virtual public Base {
public:
	D1() { cout << "D1()" << endl; }
	D1(const D1 &rhs) : Base(rhs) {}
	D1(int i) : Base(i) {}
};

class D2 : virtual public Base {
public:
	D2() { cout << "D2()" << endl; }
	D2(const D2 &rhs) : Base(rhs) {}
	D2(int i) : Base(i) {}
};

class MI : public D1, public D2 {
public:
	MI() { cout << "MI()" << endl; }
	MI(const MI &rhs) : Base(rhs), D1(rhs), D2(rhs) {}
	MI(int i) : Base(i), D1(i), D2(i) {}
};

class Final : public MI, public Class {
public:
	Final() { cout << "Final()" << endl; }
	Final(const Final &rhs) : Base(rhs), MI(rhs) {}
	Final(int i) : Base(i), MI(i) {}
};

void func()
{
	Final f;

}

int main()
{
	func();

	return 0;
}
