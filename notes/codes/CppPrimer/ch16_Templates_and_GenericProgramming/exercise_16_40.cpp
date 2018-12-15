// 练习16.40：下面的函数是否合法？如果不合法，为什么？如果合法，对可以传递的
// 实参类型有什么限制（如果有的话）？返回类型是什么？

// 合法，但是必须用于能和整数做加法的类型，返回beg绑定对象的类型

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	// 处理序列
	return *beg; // 返回序列中一个元素的拷贝
}

int main()
{
	string s;
	fcn3(s.begin(), s.end()); // OK，char可以和整数做加法

	vector<string> vec;
	//fcn3(vec.begin(), vec.end()); // 非法，string不能和整数做加法
	
	(void)vec; // ignore unuse warning

	return 0;
}
