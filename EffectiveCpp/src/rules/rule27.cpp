#include "rule27.h"

using namespace rule27;

void Rule27()
{
	// 一个函数风格的转型动作
	doSomeWork(Widget(15));

	// 一个C++风格的转型动作，更常用的应该是上面的
	doSomeWork(static_cast<Widget>(15));

	Test2();
}