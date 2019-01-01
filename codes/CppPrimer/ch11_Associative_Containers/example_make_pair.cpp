// example: 创建pair对象的函数

#include <iostream>
#include <utility> // pair类型定义在此头文件
#include <string>
#include <vector>

using namespace std;

pair<string, int>
process(vector<string> &v)
{
	// 处理v
	if (!v.empty())
		return {v.back(), v.back().size()}; // 列表初始化
	else
		return pair<string, int>();	// 隐式构造返回值
}

int main()
{
	vector<string> v{"a", "b", "ccc"};
	auto p = process(v);

	cout << p.first << " " << p.second << endl;

	return 0;
}
