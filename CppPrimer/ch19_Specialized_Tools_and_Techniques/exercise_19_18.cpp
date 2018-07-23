// 练习19.18：编写一个函数，使用count_if统计在给定的vector中有多少个空
// string。

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

void func()
{
	using namespace std;

	vector<string> vec{"", "aaa", "bbb", ""};
	int cnt = count_if(vec.begin(), vec.end(), bind(&string::empty, placeholders::_1));

	cout << "empty string count: " << cnt << endl;
}

int main()
{
	func();

	return 0;
}
