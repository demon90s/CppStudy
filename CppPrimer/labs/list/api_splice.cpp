#include <iostream>
#include <list>

// std::list::splice
// 从一个 list 转到元素给另一个

std::ostream& operator<<(std::ostream& os, const std::list<int> lst) {
	for (auto i : lst)
		os << " " << i;
	return os;
}

// void splice( const_iterator pos, list& other );
// 从 other 转移所有元素给 *this , 元素插入到 pos 之前，然后 other 变为空
// 若 other 与 *this 是同一对象则行为未定义
void Test_splice_1()
{
	std::list<int> list1 = {1, 2, 3, 4, 5};
	std::list<int> list2 = {100, 200, 300}; 

	list1.splice(list1.begin(), list2);

	std::cout << "list1:" << list1 << std::endl;
	std::cout << "list2:" << list2 << std::endl;
}

// void splice( const_iterator pos, list& other, 
//              const_iterator first, const_iterator last);
// 从 other 转移范围 [first,last) 中的元素到 *this ，元素被插入到 pos 之前
// 若 pos 是范围 [first,last) 中的迭代器则行为未定义
void Test_splice_2()
{
	std::list<int> list1 = {1, 2, 3, 4, 5};
	std::list<int> list2 = {100, 200, 300}; 
	
	auto last = list2.begin();
	std::advance(last, 2);
	list1.splice(list1.begin(), list2, list2.begin(), last);

	std::cout << "list1:" << list1 << std::endl;
	std::cout << "list2:" << list2 << std::endl;
}

int main()
{
	//Test_splice_1();
	Test_splice_2();

	return 0;
}
