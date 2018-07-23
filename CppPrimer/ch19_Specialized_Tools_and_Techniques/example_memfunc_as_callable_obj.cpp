// example: 将成员函数用作可调用对象（p744）

#include <functional>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

// 使用function
void method1()
{
	std::vector<std::string> vec{"Hello", "World", ""};

	std::function<bool(const std::string&)> fcn = &std::string::empty;
	auto it = std::find_if(vec.begin(),  vec.end(), fcn);
	if (it == vec.end())
	{
		std::cout << "no empty string" << std::endl;
	}
	else
	{
		std::cout << "has empty string" << std::endl;
	}
}

// 使用mem_fn
void method2()
{
	std::vector<std::string> vec{"Hello", "World"};

	auto it = std::find_if(vec.begin(),  vec.end(), std::mem_fn(&std::string::empty));
	if (it == vec.end())
	{
		std::cout << "no empty string" << std::endl;
	}
	else
	{
		std::cout << "has empty string" << std::endl;
	}
}

// 使用bind
void method3()
{
	std::vector<std::string> vec{"Hello", "World"};

	auto func = std::bind(&std::string::empty, std::placeholders::_1);

	auto it = std::find_if(vec.begin(),  vec.end(), func);
	if (it == vec.end())
	{
		std::cout << "no empty string" << std::endl;
	}
	else
	{
		std::cout << "has empty string" << std::endl;
	}
}

int main()
{
	method1();
	method2();
	method3();

	return 0;
}
