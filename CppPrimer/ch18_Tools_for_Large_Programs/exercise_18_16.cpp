// 练习18.16：假定在下面的代码中标记为“位置1”的地方是对于命名空间Excercise
// 中所有成员的using声明，请解释代码的含义。如果这些using声明出现在“位置2”
// 又会怎样呢？将using声明变为using指示，重新回答之前的问题。

#include <iostream>

namespace Excercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
// 位置1
//using Excercise::ivar; // error: ‘ivar’ is already declared in this scope
//using Excercise::dvar;
//using Excercise::limit;

void manip() {
	// 位置2
	using namespace Excercise;

	double dvar = 3.1416; // 与命名空间Excercise的dvar无关
	int iobj = limit + 1;
	//++ivar; // 如果使用using指示，则有error: reference to ‘ivar’ is ambiguous
	// 改成：
	++Excercise::ivar;
	++::ivar; // 使用的是全局空间的ivar

	// ignore warning
	(void)dvar;
	(void)iobj;
}

int main()
{
	return 0;
}
