/*
 * 练习5.17：假设有两个包含整数的vector对象，编写一段程序，检验其中一个vector对象是否是另一个的前缀。为了实现这一目标，对于两个不等长的vector对象，只需挑出长度较短的那个，把它的所有元素和另一个vector对象比较即可。例如，如果两个vector对象的元素分别是0, 1, 1, 2和0, 1, 1, 2, 3, 5, 8，则程序返回的结果应该为真。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> v1 = {0, 1, 1, 2};
	//vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};
	vector<int> v2 = {0, 1, 2, 2, 3, 5, 8};

	auto min_sz = v1.size() < v2.size() ? v1.size() : v2.size();

	bool is_prefix = true;
	for (decltype(min_sz) i = 0; i < min_sz; ++i) {
		if (v1[i] != v2[i]) {
			is_prefix = false;
			break;
		}
	}

	if (is_prefix) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	return 0;
}
