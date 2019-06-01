/*
 * 练习7.43：假定有一个名为NoDefault的类，它有一个接受int的构造函数，但是
 * 没有默认构造函数。定义类C，C有一个NoDefault类型的成员，定义C的默认构造
 * 函数。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class NoDefault
{
public:
	NoDefault(int) {}
};

class C
{
public:
	C() : nd(0) {}
private:
	NoDefault nd;
};

int main()
{
	C c;
	return 0;
}
