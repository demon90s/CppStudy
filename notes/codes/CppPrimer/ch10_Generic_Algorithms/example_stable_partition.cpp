// example: stable_partition，将序列分为两组，满足谓词的放在前面一组

#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec{3, 5, 1, 100, 283, 9, 111, 8, 654, 4};

	// 从小到大排序，但大于等于100的放在前面
	
	std::sort(vec.begin(), vec.end());
	std::stable_partition(vec.begin(), vec.end(), [](int element) { return element >= 100; });

	for (auto i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
