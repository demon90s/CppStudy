/*
 * 练习6.46：能把isShorter函数定义成constexpr函数吗？如果能，将他改写成constexpr函数；
 * 如果不能，说明原因。
 */

// 不能，G++报错：error: call to non-constexpr function，因为其参数非字面值类型。
// 关于此问题的一个讨论：https://github.com/ReadingLab/Discussion-for-Cpp/issues/22

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 比较两个string对象的长度
constexpr
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	cout << isShorter("Hello", "Hi") << endl;

	return 0;
}
