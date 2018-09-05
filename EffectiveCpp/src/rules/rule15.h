// 条款15：在资源管理类中提供对原始资源的访问
#ifndef __RULE15_H__
#define __RULE15_H__

#include <iostream>

extern void Rule15();

namespace rule15
{
	// “投资类型”继承体系中的root class
	class Investment
	{
	public:
		Investment() { std::cout << "Investment()" << std::endl; }
		~Investment() { std::cout << "~Investment()" << std::endl; }
	};

	// 通过工厂函数分配动态对象
	inline Investment* createInvestment()
	{
		return new Investment();
	}

	inline int daysHeld(const Investment* pi)
	{
		return 0;
	}

	// 一组 C API , inline 只是为了方便定义
	typedef int* FontHandle;
	inline FontHandle getFont() { return new int(42); }
	inline void releaseFont(FontHandle fh) { delete fh; }
	inline void changeFontSize(FontHandle fh, int newSize) {}

	class Font
	{
	public:
		explicit Font(FontHandle fh) : f(fh) {}
		~Font() { releaseFont(f); }

		// 我们可能需要将 Font 转换成其原始资源 FontHandler 以适应 C API
		FontHandle get() const { return f; }		// 显式转换
		operator FontHandle() const { return f; }	// 隐式转换，不安全的做法

	private:
		FontHandle f;			// 原始资源
	};
}

#endif // __RULE15_H__