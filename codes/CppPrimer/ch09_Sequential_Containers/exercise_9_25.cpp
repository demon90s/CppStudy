// 练习9.25：对于第312页中删除一个范围内的元素的程序，如果elem1与elem2相等会发生什么？
// 如果elem2是尾后迭代器，或者elem1和elem2皆为尾后迭代器，又会发生什么？

// 如果elem1与elem2相等、或者都是尾后迭代器，那么什么都不会发生
// 如果elem2是尾后迭代器，则删除[elem1, elem2)范围内的元素

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> lst;
	auto end = lst.end();

	lst.erase(end, end); // nothing happened

	//lst.erase(end);	// crash

	return 0;
}
