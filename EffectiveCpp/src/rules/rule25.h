// 条款25：考虑写出一个不抛异常的 swap 函数
#ifndef __RULE25_H__
#define __RULE25_H__

#include <vector>

extern void Rule25();

namespace rule25
{
	class WidgetImpl {
	public:
		WidgetImpl() 
		{
			// 故意创建一堆数据
			for (int i = 0; i < 100000; i++) v.push_back(3.14);
		}

	private:
		int a, b, c;			// 可能有很多数据
		std::vector<double> v;	// 意味着复制时间很长
	};

	class Widget {				// 这个 class 使用 pimpl 手法
	public:
		Widget() : pImpl(new WidgetImpl) {}
		~Widget() { delete pImpl; }

		Widget(const Widget& rhs)	// 复制 Widget 时，令它复制其 WidghtImpl 对象
			: pImpl(new WidgetImpl(*rhs.pImpl))
		{}

		Widget& operator=(const Widget& rhs)
		{
			auto p = new WidgetImpl(*rhs.pImpl);
			delete pImpl;
			pImpl = p;
			return *this;
		}

		void swap(Widget& other)
		{
			using std::swap;
			swap(pImpl, other.pImpl);
		}

	private:
		WidgetImpl *pImpl;		// 指针，所指对象含 Widget 数据
	};

	inline void swap(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}

#endif // __RULE25_H__