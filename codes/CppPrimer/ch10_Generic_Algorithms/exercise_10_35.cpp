// 练习10.35：使用普通迭代器逆序打印一个vector。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v{1, 2, 3, 4, 5};

	for (auto it = v.cend(); it != v.cbegin();)
		cout << *--it << " ";
	cout << endl;

	return 0;
}
