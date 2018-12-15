// 练习14.42：使用标准库函数对象及适配器定义一条表达式，令其
// (a) 统计大于1024的值有多少个。
// (b) 找到第一个不等于pooh的字符串。
// (c) 将所有的值乘以2。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void func_a()
{
	vector<int> vec = {1, 2, 1025, 2000, 1024};

	auto adapter = bind(greater<int>(), placeholders::_1, 1024);
	auto cnt = count_if(vec.cbegin(), vec.cend(), adapter);

	cout << cnt << endl;
}

void func_b()
{
	vector<string> vec = {"pooh", "Hi", "A"};

	auto adapter = bind(not_equal_to<string>(), placeholders::_1, "pooh");
	auto it = find_if(vec.cbegin(), vec.cend(), adapter);
	if (it != vec.cend())
	{
		cout << *it << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void func_c()
{
	vector<int> vec = {1, 2, 3, 4};

	auto adapter = bind(multiplies<int>(), placeholders::_1, 2);
	transform(vec.cbegin(), vec.cend(), vec.begin(), adapter);

	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//func_a();
	//func_b();
	func_c();

	return 0;
}
