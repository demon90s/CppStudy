#include "rule10.h"

extern void Rule10()
{
	int i = 42;
	rule10::Widget w;
	rule10::Widget w2;

	w2 = w = i;

	rule10::print(std::cout, w2) << std::endl;
}