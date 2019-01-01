// example: 改变容器的循环程序（p316）

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 傻瓜循环，删除偶数元素，复制每个奇数元素
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto beg = vec.begin();
	while (beg != vec.end()) {
		if (*beg % 2) {
			beg = vec.insert(beg, *beg);
			beg += 2; // 向前移动迭代器，跳过当前元素以及插入到它之前的元素
		}
		else
			beg = vec.erase(beg);
	}

	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	return 0;
}
