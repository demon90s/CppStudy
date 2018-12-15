// 练习12.16：如果你试图拷贝或赋值unique_ptr，编译器并不总是能给出易于理解的错误信息。
// 编写包含这种错误的程序，观察编译器如何诊断这种错误。

#include <iostream>
#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> p1(new int(1));
	//unique_ptr<int> p2(p1); // 错误：unique_ptr不支持拷贝，打开注释->编译，观察错误

	return 0;
}
