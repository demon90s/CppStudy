// 练习18.23：使用练习18.22的继承体系以及下面定义的类D，同时假定每个类都定义
// 了默认构造函数，请问下面的哪些类型转换是不被允许的？

#include <iostream>

#define USE_VAR(v) (void)(v)

using namespace std;

class A { public: A() { cout << "A()" << endl; } };
class B : public A { public: B() { cout << "B()" << endl; } };
class C : public B { public: C() { cout << "C()" << endl; } };
class X { public: X() { cout << "X()" << endl; } };
class Y { public: Y() { cout << "Y()" << endl; } };
class Z : public X, public Y { public: Z() { cout << "Z()" << endl; } };
class MI : public C, public Z { public: MI() { cout << "MI()" << endl; } };

class D : public X, public C {};

int main()
{
	D *pd = new D;
	USE_VAR(pd);

	// (a) 
	X *px = pd; // OK
	USE_VAR(px);

	// (b)
	A *pa = pd; // OK
	USE_VAR(pa);

	// (c)
	B *pb = pd; // OK
	USE_VAR(pb);

	// (d)
	C *pc = pd; // OK
	USE_VAR(pc);

	return 0;
}
