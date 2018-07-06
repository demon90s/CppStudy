// 练习19.3：已知存在如下的继承体系，其中每个类分别定义了一个公有的默认构造函数
// 和一个虚析构函数。哪一个dynamic_cast将失败？

#include <iostream>

class A { public: virtual ~A() {} };
class B : public A {};
class C : public B {};
class D : public A {}; // ps: 书本中是如这样写的：class D : public B, public A {}; 然而这样无法通过编译

int main()
{
	// a succ
	{
		A *pa = new C;
		B *pb = dynamic_cast<B*>(pa);
		std::cout << (pb ? "succ" : "failed") << std::endl;

		delete pa;
	}

	// b 失败
	{
		B *pb = new B;
		C *pc = dynamic_cast<C*>(pb);
		std::cout << (pc ? "succ" : "failed") << std::endl;

		delete pb;
	}

	// c 失败
	{
		A *pa = new D;
		B *pb = dynamic_cast<B*>(pa);
		std::cout << (pb ? "succ" : "failed") << std::endl;

		delete pa;
	}

	return 0;
}
