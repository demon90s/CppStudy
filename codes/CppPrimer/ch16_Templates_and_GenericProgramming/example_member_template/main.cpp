// example: 成员模板（p595）

#include <iostream>
#include "DebugDelete.h"

using namespace std;

void func1()
{
	double *p = new double;
	DebugDelete d; // 可像delete表达式一样使用的对象
	d(p); // 调用DebugDelete::operator()(double*)，释放p
}

void func2()
{
	// 销毁p指向的对象
	// 实例化DebugDelete::operator()<int>(int*)
	unique_ptr<int, DebugDelete> p(new int, DebugDelete());
}

int main()
{
	//func1();
	func2();

	return 0;
}
