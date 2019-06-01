// 练习19.10：已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数
// 和一个虚析构函数。下面的语句将打印哪些类的名字？

#include <iostream>
#include <typeinfo>

using namespace std;

class A { public: virtual ~A() {} };
class B : public A {};
class C : public B {};

int main()
{
	// (a) 指向A的指针类型
	{
		A *pa = new C;
		cout << typeid(pa).name() << endl;
	}

	// (b) 指向A的指针类型
	{
		C cobj;
		A &ra = cobj;
		cout << typeid(&ra).name() << endl;
	}

	// (c) B类型
	{
		B *px = new B;
		A &ra = *px;
		cout << typeid(ra).name() << endl;
	}

	return 0;
}
