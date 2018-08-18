// 条款10：
#ifndef __RULE10_H__
#define __RULE10_H__

#include <iostream>

extern void Rule10();

// 为了实现“连锁赋值”，赋值操作符必须返回一个reference指向操作符左侧实参
// 这是你为classes实现赋值操作时应该遵循的协议
namespace rule10
{
	class Widget
	{
		friend std::ostream& print(std::ostream &os, const Widget &w);
	public:
		Widget() : i(0) {}
		Widget& operator=(const Widget &rhs)
		{
			i = rhs.i;
			return *this;
		}

		Widget& operator+=(const Widget& rhs)	// 适用于+=, -=, *=, 等等
		{
			i += rhs.i;
			return *this;
		}

		Widget& operator=(int rhs)	// 也适用，即使参数类型不符合协定
		{
			i = rhs;
			return *this;
		}

	private:
		int i;
	};

	inline std::ostream& print(std::ostream &os, const Widget &w)
	{
		os << "Widget: " << w.i;
		return os;
	}
}

#endif // __RULE10_H__