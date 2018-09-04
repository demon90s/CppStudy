// 条款17：以独立语句将 newed 对象置入智能指针
#ifndef __RULE17_H__
#define __RULE17_H__

#include <stdexcept>
#include <memory>

extern void Rule17();

namespace rule17
{
	class Widget
	{
		char buffer[1024 * 1024];	// 测试内存泄漏的buffer， vs2015 下观察
	};

	inline int priority()
	{
		// 会抛出一个异常的函数
		throw std::runtime_error("exception");
	}

	// 一个可能会发生内存泄漏的函数，籍由错误的初始化 pw
	inline void processWidget(std::shared_ptr<Widget> pw, int priority) {}
}

#endif // __RULE17_H__