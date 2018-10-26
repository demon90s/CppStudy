// 条款27：尽量少做转型动作
#ifndef __RULE27_H__
#define __RULE27_H__

#include <iostream>

extern void Rule27();

namespace rule27
{
	// 作者的唯一一个使用旧式转型的时机，调用一个 explicit 构造函数创建出对象传递给一个函数
	class Widget {
	public:
		explicit Widget(int size) {}
	};
	inline void doSomeWork(const Widget& w) {}

	// 两个指针的值可能不相同（这在多重继承中几乎一直发生）
	class Base1 {};
	class Base2 {};
	class Derived : public Base1, public Base2 {};
	inline void Test2() {
		Derived d;
		Base2* pb = &d;

		std::cout << "pb: " << pb << std::endl;
		std::cout << "&d: " << &d << std::endl;
	}
}

#endif // __RULE27_H__