/*
 * 练习7.5：在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否
 * 应该是const的呢？解释原因。
 */

// 应该是const的，因为这样就可以让常量对象调用此成员函数，否则会因为无法传入
// 顶层const this指针导致无法调用。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

struct Person
{
	std::string GetName() const { return name; }
	std::string GetAddr() const { return addr; }

	std::string name;
	std::string addr;
};

int main()
{
	return 0;
}
