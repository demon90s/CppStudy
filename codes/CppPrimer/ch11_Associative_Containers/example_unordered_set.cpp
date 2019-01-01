// example: 无序容器对关键字的要求（p396）

#include <iostream>
#include <unordered_set>

#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

size_t hasher(const Sales_data &sd)
{
	return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn();
}

int main()
{
	using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>;

	SD_multiset bookstore(0, hasher, eqOp);

	return 0;
}
