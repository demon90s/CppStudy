#include "rule24.h"

using namespace rule24;

void Rule24()
{
	Rational oneEight(1, 8);
	Rational result = oneEight * 2; // OK
	result = 2 * oneEight;			// 如果乘法操作是 member 函数，那么不 OK

	std::cout << result << std::endl;
}