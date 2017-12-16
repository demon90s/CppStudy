// 练习10.1：头文件algorithm中定义了一个名为count的函数，它类似find，接受
// 一对迭代器和一个值作为参数。count返回给定值在序列中出现的次数。编写程序，
// 读取int序列存入vector中，打印有多少个元素的值等于给定值。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ivec;
	int i;
	while (cin >> i)
		ivec.push_back(i);

	int n = 5;
	cout << count(ivec.begin(), ivec.end(), n) << endl;

	return 0;
}
