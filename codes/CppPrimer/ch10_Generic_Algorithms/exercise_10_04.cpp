// 练习10.4：假定v是一个vector<double>，那么调用accumulate(v.cbegin(), v.cend(), 0)
// 有何错误（如果存在的话）？

// 没有编译错误，因为double可以转换成int。但结果却会丢失精度。

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	vector<double> ivec = {1.1, 2.2, 3.3, 4.4, 5.5};

	cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;

	return 0;
}
