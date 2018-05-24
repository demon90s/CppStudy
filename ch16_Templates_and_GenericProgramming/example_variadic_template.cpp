// example: 可变参数模板（p618）

#include <string>
#include <iostream>

using namespace std;

// Args是一个模板参数包；rest是一个函数参数包
// Args表示零个或多个模板类型参数
// rest表示零个或多个函数参数
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
	cout << sizeof...(Args) << endl;	// 类型参数的数目
	cout << sizeof...(rest) << endl;	// 函数参数的数目
	cout << "\n";
}

int main()
{
	int i = 0; double d = 3.14; string s = "how now brown cow";

	foo(i, s, 42, d);		// 包中有三个参数
	foo(s, 42, "hi");		// 包中有两个参数
	foo(d, s);				// 包中有一个参数
	foo("hi");				// 空包

	return 0;
}
