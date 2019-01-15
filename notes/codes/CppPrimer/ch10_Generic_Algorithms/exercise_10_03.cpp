// 练习10.3：用accumulate求一个vector<int>中的元素之和。

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	vector<int> ivec = {1, 2, 3, 4, 5};

	cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;

	return 0;
}
