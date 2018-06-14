// 练习18.22：已知存在如下所示的类的继承体系，每个类都定义了一个默认构造函数。
// 对于下面的定义来说，构造函数的执行顺序是怎样的？MI mi;

// 为了验证结果，采用自定义的默认构造函数，打印一下。

#include <iostream>

using namespace std;

class A { public: A() { cout << "A()" << endl; } };
class B : public A { public: B() { cout << "B()" << endl; } };
class C : public B { public: C() { cout << "C()" << endl; } };
class X { public: X() { cout << "X()" << endl; } };
class Y { public: Y() { cout << "Y()" << endl; } };
class Z : public X, public Y { public: Z() { cout << "Z()" << endl; } };
class MI : public C, public Z { public: MI() { cout << "MI()" << endl; } };

int main()
{
	// 推导构造顺序：
	// C, Z, MI
	// B -> C, X, Y, Z, MI
	// A -> B -> C, X, Y, Z, MI

	MI mi;

	return 0;
}
