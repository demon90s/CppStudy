// test: set的列表初始化

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> iset = {1, 2, 2, 3, 3, 4};

	for (auto i : iset)
		cout << i << " ";	// 1 2 3 4，不会有重复的
	cout << endl;

	return 0;
}
