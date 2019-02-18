/*
	#include <numeric>
	T
	accumulate(InputIterator beg, InputIterator end, T initValue);

	T
	accumulate(InputIterator beg, InputIterator end, T initValue, BinaryFunc op);

	没有 op 的版本求取区间 [beg, end) 的元素总和，并加上 initValue
	带 op 的版本则把加法改成 op 。
*/

#include <functional>
#include <vector>
#include <iostream>
#include <numeric>

std::ostream& operator<<(std::ostream &os, const std::vector<int> &v)
{
	for (auto i : v)
		os << " " << i;
	return os;
}

void Test1()
{
	std::vector<int> v {1, 2, 3, 4, 5};

	int sum = std::accumulate(v.begin(), v.end(), 0);

	std::cout << "accumulate(+):" << v << std::endl;
	std::cout << sum << std::endl;
}

void Test2()
{
	std::vector<int> v {1, 2, 3, 4, 5};

	int sum = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

	std::cout << "accumulate(*):" << v << std::endl;
	std::cout << sum << std::endl;
}

int main()
{
	//Test1();
	Test2();

	return 0;
}
