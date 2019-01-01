// 练习9.27：编写程序，查找并删除forward_list<int>中的奇数元素。

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	// 删除forward_list中的奇数元素
	
	forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
	auto prev = flst.before_begin();	// 表示flst的首前元素
	auto curr = flst.begin();			// 表示flst中的第一个元素
	while (curr != flst.end()) {
		if (*curr % 2)
			curr = flst.erase_after(prev);
		else {
			prev = curr;	// 移动迭代器curr，指向下一个元素，prev指向curr之前的元素
			++curr;
		}
	}

	for (auto i : flst)
		cout << i << " ";
	cout << endl;

	return 0;
}
