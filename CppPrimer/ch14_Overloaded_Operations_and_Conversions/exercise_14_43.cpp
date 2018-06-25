// 练习14.43：使用标准库函数对象判断一个给定的int值是否能被int容器中的所有元素整除。

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
	vector<int> vec = {4, 6, 10};
	int n = 0;
	cin >> n;

	auto check_func = modulus<int>();

	bool can_modulus = true;
	for (auto i : vec)
	{
		if (check_func(i, n) != 0)
		{
			can_modulus = false;
			break;
		}
	}

	cout << "Can modulus: " << can_modulus << endl;

	return 0;
}
