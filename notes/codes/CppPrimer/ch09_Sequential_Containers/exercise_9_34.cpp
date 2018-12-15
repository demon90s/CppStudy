// 练习9.34：假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环
// 的行为，然后编写程序验证你的分析是否正确。

/*
 * iter = vi.begin();
 * while (iter != vi.end())
 * 	if (*iter % 2)
 * 		iter = vi.insert(iter, *iter);
 * 	++iter;
 */

// 程序的目的就是复制一下奇数的值，但代码里语法都错了，而且会死循环。因此自己
// 实现一个。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vi{1, 4, 5, 7, 8, 9};

	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);
			iter += 2;
		}
		else
			++iter;
	}

	for (auto i : vi)
		cout << i << " ";
	cout << endl;

	return 0;
}
