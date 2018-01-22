// 练习11.17：假定c是一个string的multiset，v是一个string的vector，
// 解释下面的调用。指出每个调用是否合法。

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v{"h", "a", "u"};
	multiset<string> c;

	copy(v.begin(), v.end(), inserter(c, c.end())); // 合法
	//copy(v.begin(), v.end(), back_inserter(c)); // 非法，multiset没有push_back操作
	copy(c.begin(), c.end(), inserter(v, v.end())); // 合法
	copy(c.begin(), c.end(), back_inserter(v));	// 合法

	return 0;
}
