#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

// forward_list 不提供 size() 操作，可以用如下方法求取其元素个数
void test_get_size()
{
	std::forward_list<int> l {1, 2, 3, 4, 5};

	std::cout << "l.size(): " << std::distance(l.begin(), l.end()) << std::endl;
}

// forward_list 的插入，必须利用前导元素去执行，并采取特殊的 insert_after() 操作
void test_insert()
{
	std::forward_list<int> l{1, 2, 3};

	// insert 77 88 99 at beginning
	l.insert_after(l.before_begin(), {77, 88, 99});

	std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

// forward_list 的删除也和插入一样，必须握有欲删除元素的前导，才可以删除它
void test_erase()
{
	// 删掉第一个奇数
	std::forward_list<int> l {2, 4, 5, 7, 8, 9};

	auto posBefore = l.before_begin();
	for (auto pos = l.begin(); pos != l.end(); ++pos, ++posBefore) {
		if (*pos % 2 != 0)
			break;
	}

	l.erase_after(posBefore);

	std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

// 运用实例
void printLists(const std::string &s,
		const std::forward_list<int>& l1,
		const std::forward_list<int>& l2)
{
	std::cout << s << std::endl;
	std::cout << " list1: ";
	std::copy(l1.cbegin(), l1.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << " list2: ";
	std::copy(l2.cbegin(), l2.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

void test()
{
	// create two forward lists
	std::forward_list<int> list1 = {1, 2, 3, 4};
	std::forward_list<int> list2 = {77, 88, 99};
	printLists("initial:", list1, list2);

	// insert six new element at the beginning of list2
	list2.insert_after(list2.before_begin(), 99);
	list2.push_front(10);
	list2.insert_after(list2.before_begin(), {10, 11, 12, 13});
	printLists("6 new elems:", list1, list2);

	// insert all elements of list2 at the beginning of list1
	list1.insert_after(list1.before_begin(),
			   list2.begin(), list2.end());
	printLists("list2 into list1:", list1, list2);

	// delete second element and elements after element with value 99
	list2.erase_after(list2.begin());
	list2.erase_after(find(list2.begin(), list2.end(), 99), list2.end());
	printLists("delete 2nd and after 99:", list1, list2);

	// sort list1, assign it to list2, and remove duplicates
	list1.sort();
	list2 = list1;
	list2.unique();
	printLists("sorted and unique:", list1, list2);

	// merge both sorted lists into list1
	list1.merge(list2);
	printLists("merged:", list1, list2);
}

int main()
{
	//test_get_size();
	//test_insert();
	//test_erase();
	test();

	return 0;
}
