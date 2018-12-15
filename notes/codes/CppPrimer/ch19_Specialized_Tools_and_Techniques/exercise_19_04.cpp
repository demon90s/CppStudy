// 练习19.4：使用上一个练习定义的类改写下面的代码，将表达式*pa转换成类型C&。

#include <iostream>
#include <typeinfo>

class A { public: virtual ~A() {} };
class B : public A {};
class C : public B {};
class D : public A {};

int main()
{
	A *pa = new B;

	/*
	if (C *pc = dynamic_cast<C*>(pa))
	{
		// 使用C的成员
		(void)pc;
	}
	else
	{
		// 使用A的成员
	}
	*/

	try {
		C& c = dynamic_cast<C&>(*pa);
		(void)c;
	} catch (std::bad_cast) {
		// 转换失败
		std::cout << "dynamic_cast failed" << std::endl;
	}

	return 0;
}
