// 练习10.24：给定一个string，使用bind和check_size在一个int的vector中
// 查找第一个大于string长度的值。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() < sz;
}

int main()
{
	string s = "www";
	vector<int> v = {1, 2, 3, 4, 5};

	auto it = find_if(v.begin(), v.end(), bind(check_size, s, _1));
	
	if (it != v.end())
		cout << *it << endl;
	else
		cout << "not find" << endl;

	return 0;
}
