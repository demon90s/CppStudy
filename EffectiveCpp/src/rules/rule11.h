// 条款11：在operator=中处理“自我赋值”
#ifndef __RULE11_H__
#define __RULE11_H__

#include <iostream>

extern void Rule11();

namespace rule11
{
	class Widget
	{
	public:
		Widget(int i) : ip(new int(i)) {}
		~Widget() { delete ip; }
		Widget(const Widget &w) : ip(new int(*w.ip)) {}

		void swap(Widget &w)
		{
			std::swap(ip, w.ip);
		}

		void print() { std::cout << *ip << std::endl; }

		Widget& operator=(const Widget& rhs);

	private:
		int *ip;
	};

	inline Widget& Widget::operator=(const Widget& rhs)
	{
		// 错误的例子，无法处理自赋值
		if (bool bug = false)
		{
			delete ip;
			ip = new int(*rhs.ip);
			return *this;
		}

		// 证同测试，可以自赋值，但不具备异常安全性（即new抛出了异常则无法还原）
		if (bool identity_test = false)
		{
			if (this == &rhs) return *this;

			delete ip;
			ip = new int(*rhs.ip);
			return *this;
		}

		// 正确的做法，保存指针的副本，成功new后，再delete
		if (bool correct = false)
		{
			int *tmp = ip;
			ip = new int(*rhs.ip);
			delete tmp;
			return *this;
		}

		// copy and swap技术，也拥有异常安全，需要更多的代码（一个copy构造函数、一个自定义的swap函数）
		if (bool copy_and_swap = true)
		{
			Widget tmp(rhs);	// 临时的副本是安全的，它会自动销毁
			swap(tmp);
			return *this;
		}

		return *this;
	}
}

#endif // __RULE11_H__