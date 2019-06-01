// 练习9.15：编写程序，判定两个vector<int>是否相等。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {1, 2, 3};

	if (v1 == v2)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	return 0;
}
