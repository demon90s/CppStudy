// example: 介绍back_inserter(p341)

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec; // 空向量
	auto it = back_inserter(vec); // 通过它赋值会将元素添加到vec中
	*it = 42; // vec中现在有一个元素，值为42

	for(auto i : vec)
		cout << i << " ";
	cout << endl;

	return 0;
}
