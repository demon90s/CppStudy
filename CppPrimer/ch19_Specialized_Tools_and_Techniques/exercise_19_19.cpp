// 练习19.19：编写一个函数，令其接受vector<Sales_data>并查找平均价格高于
// 某个值的第一个元素。

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include "../ch07_Classes/example_Sales_data/Sales_data.h"

void func()
{
	using namespace std;

	vector<Sales_data> vec;
	vec.emplace_back("0-201-70353-X", 4, 24.99);

	double avg_price = 0;
	cout << "enter avg_price: ";
	cin >> avg_price;

	auto it = find_if(vec.begin(), vec.end(), bind(&Sales_data::AvgPriceMoreThan, placeholders::_1, avg_price));
	if (it != vec.end())
	{
		cout << "find, info: " << *it << endl;
	}
	else
	{
		cout << "no find" << endl;
	}
}

int main()
{
	func();

	return 0;
}
