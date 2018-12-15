// 练习10.17：重写10.3.1节练习10.12（第345页）的程序，在对sort的调用中使用lambda
// 来替代函数compareIsbn。

// 练习10.12：编写名为compareIsbn的函数，比较两个Sales_data对象的isbn()
// 成员。使用这个函数排序一个保存Sales_data对象的vector。

// ./exercise_10_17 < ../ch07_Classes/data/book_sales

#include <iostream>
#include <vector>
#include <algorithm>

#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

int main()
{
	vector<Sales_data> vec;
	Sales_data sd;
	while (read(cin, sd))
		vec.push_back(sd);

	sort(vec.begin(), vec.end(), [](const Sales_data &lhs, const Sales_data &rhs)
		{ return lhs.isbn() < rhs.isbn(); });

	for (const auto &item : vec)
		print(cout, item) << endl;

	return 0;
}
