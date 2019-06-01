// example: 可调用对象与function（p511）

// function 是一个模板类型, 它有一个调用模式的额外信息, 比如 int(int, int) 代表参数是 (int, int) 返回值是 int 的可调用对象
// 可以使用这样的可调用对象的实例来初始化 function 对象

#include <iostream>
#include <map>
#include <functional>

// 几种不同类型的可调用对象：

int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide {
	int operator()(int denominator, int divisor) {
		return denominator / divisor;
	}
};

using namespace std;

int main()
{
	// 构建从运算符到函数指针的映射关系，其中函数接受两个int、返回一个int
	map<string, function<int(int, int)>> binops = {
		{"+", add},					// 函数指针
		{"-", std::minus<int>()},	// 标准库函数对象
		{"/", divide()},			// 用户定义的函数对象
		{"*", [](int i, int j) { return i * j; }}, // 未命名的lambda
		{"%", mod}					// 命名了的lambda对象		
	};

	cout << binops["+"](1, 2) << endl;
	cout << binops["-"](1, 2) << endl;
	cout << binops["/"](1, 2) << endl;
	cout << binops["*"](1, 2) << endl;
	cout << binops["%"](1, 2) << endl;

	return 0;
}
