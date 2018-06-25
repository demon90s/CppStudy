// 练习9.31：第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或
// forward_list。为什么？修改程序，使之也能用于这些类型。

// list的迭代器不支持+=2这样的算术运算
// forward_list并未定义insert和erase成员

#include <iostream>
#include <list>
#include <forward_list>

using namespace std;

// for list
void func1()
{
	list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto beg = lst.begin();
	while (beg != lst.end()) {
		if (*beg % 2) {
			beg = lst.insert(beg, *beg);
			++beg, ++beg; // 向前移动迭代器，跳过当前元素以及插入到它之前的元素
		}
		else
			beg = lst.erase(beg);
	}

	for (auto i : lst)
		cout << i << " ";
	cout << endl;
}

// for forward_list
void func2()
{
	forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto beg = flst.begin();
	auto pre = flst.before_begin();
	while (beg != flst.end()) {
		if (*beg % 2) {
			beg = flst.insert_after(beg, *beg);
			pre = beg++;
		}
		else {
			beg = flst.erase_after(pre);
		}
	}

	for (auto i : flst)
		cout << i << " ";
	cout << endl;
}

int main()
{
	func1();
	func2();

	return 0;
}
