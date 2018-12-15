// 练习10.28：一个vector中保存1到9，将其拷贝到三个其他容器中。分别使用
// inserter、back_inserter和front_inserter将元素添加到三个容器中。对每
// 种inserter，估计输出序列是怎样的，运行程序验证你的估计是否正确。

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

	vector<int> v1, v2;
	list<int> v3;

	copy(v.begin(), v.end(), inserter(v1, v1.begin())); // 1 2 3 ...
	copy(v.begin(), v.end(), back_inserter(v2)); 		// 1 2 3 ...
	copy(v.begin(), v.end(), front_inserter(v3)); 		// 9 8 7 ...

	for_each(v1.begin(), v1.end(), [](int i) { cout << i << " "; }); cout << endl;
	for_each(v2.begin(), v2.end(), [](int i) { cout << i << " "; }); cout << endl;
	for_each(v3.begin(), v3.end(), [](int i) { cout << i << " "; }); cout << endl;

	return 0;
}
