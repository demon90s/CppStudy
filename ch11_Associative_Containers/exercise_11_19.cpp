// 练习11.19：定义一个变量，通过对11.2.2节（第378页）中的名为bookstore的multiset
// 调用begin()来初始化这个变量。写出变量的类型，不要使用auto或decltype。

// 练习11.11：不使用decltype重新定义bookstore

#include <iostream>
#include <set>

#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

typedef bool (*compare_func)(const Sales_data &lhs, const Sales_data &rhs);

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	multiset<Sales_data, compare_func> bookstore(compareIsbn);

	multiset<Sales_data, compare_func>::iterator it = bookstore.begin();

	return 0;
}
