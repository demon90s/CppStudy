// 练习10.6：编写程序，使用fill_n将一个序列中的int值都设置为0。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec{1, 2, 3, 4, 5};

	fill_n(ivec.begin(), ivec.size(), 0);

	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}
