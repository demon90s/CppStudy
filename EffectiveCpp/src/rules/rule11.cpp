#include "rule11.h"

using namespace rule11;

extern void Rule11()
{
	Widget w(42);
	w = w;				// 自赋值

	w.print();
}