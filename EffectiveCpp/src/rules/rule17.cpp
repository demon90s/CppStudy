#include "rule17.h"

#ifdef _MSC_VER
#include <windows.h>
#endif

#ifdef __unix
#include <unistd.h>
#endif

using namespace rule17;

static void sleep(int second)
{
#ifdef _MSC_VER
	Sleep(second * 1000);
#endif

#ifdef __unix
	::sleep(second);
#endif
}

void Rule17()
{
	// 错误的调用，籍由异常抛出前，newed 指针未能初始化给智能指针，从而产生内存泄漏
	/*for (int i = 0; i < 100; ++i)
	{
		try
		{
			processWidget(std::shared_ptr<Widget>(new Widget()), priority());
		}
		catch ( ... ) {}
		
		sleep(1);
	}*/

	// 正确的做法，用独立语句把 newed 对象存储于智能指针内
	for (int i = 0; i < 100; ++i)
	{
		try
		{
			std::shared_ptr<Widget> pw(new Widget);
			processWidget(pw, priority());
		}
		catch (...) {}

		sleep(1);
	}
}