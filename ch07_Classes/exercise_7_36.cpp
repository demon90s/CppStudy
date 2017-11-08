/*
 * 练习7.36：下面的初始值是错误的，请找出问题所在并尝试修改它。
 */

/*
 * 最好令构造函数初始值的顺序与成员声明的顺序保持一致。而且如果可能的
 * 话，尽量避免使用某些成员初始化其他成员。（p259）
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// rem先于base初始化，但却依赖于base的初始值，故而是错误的
// 但g++只是报告了warning
/*
struct X {
	X (int i, int j) : base(i), rem(base % j) {}

	int rem, base;
};
*/

// 只需要调整数据成员的声明顺序即可
struct X {
	X (int i, int j) : base(i), rem(base % j) {}

	int base, rem;
};

int main()
{
	return 0;
}
