// 练习16.45：给定下面的模板，如果我们对一个像42这样的字面常量调用g，解释会发生
// 什么？如果我们对一个int类型的变量调用g呢？

#include <iostream>
#include <vector>

using namespace std;

template<typename T> void g(T&& val) { vector<T> v; }

int main()
{
	g(42); // OK，T被推导为int，可以定义一个vector<int>
	
	//int i = 0;
	//g(i);  // ERROR，T被推导为int&，不能定义一个vector<int&>

	return 0;
}
