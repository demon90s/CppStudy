// 使用迭代器进行二分搜索

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	vector<int> ivec = {1, 3, 4, 5, 8, 9, 10};
	int sought = 0;
	cout << "Enter a number you want to find:" << endl;
	cin >> sought;

	// ivec必须是有序的
	// beg和end表示我们的搜索的范围
	auto beg = ivec.begin(), end = ivec.end();
	auto mid = ivec.begin() + (end - beg) / 2; // 初始状态下的中间点

	// 当还有元素尚未检查并且我们还没有找到sought时执行循环
	while (mid != end && *mid != sought) {
		if (sought < *mid)
			end = mid;
		else
			beg = mid + 1;
		mid = beg + (end - beg) / 2;	// 新的中间点
	}

	if (mid != end)
		cout << "Find the number" << endl;
	else
		cout << "Not find the number" << endl;

	return 0;
}
