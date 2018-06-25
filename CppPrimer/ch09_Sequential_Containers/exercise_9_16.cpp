// 练习9.16：重写上一题的程序，比较一个list<int>中的元素和一个vector<int>
// 中的元素。

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vec = {1, 2, 3};
	list<int> lst = {1, 2, 3};

	vector<int> tmp_vec(lst.begin(), lst.end());
	if (vec == tmp_vec)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	return 0;
}
