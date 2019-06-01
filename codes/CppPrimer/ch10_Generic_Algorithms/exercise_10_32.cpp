// 练习10.32：重写1.6节（第21页）的书店程序，使用一个vector保存交易记录，
// 使用不同的算法完成处理。使用sort和10.3.1节（第345页）中的compareIsbn
// 函数来排序交易记录，然后使用find和accumulate求和。

/*
 * 练习1.25：借助网站上的Sales_item.h头文件，编译并运行本节给出的书店程序。
 */

// ./exercise_10_32 < ../data/book_sales

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "../ch01_Getting_Started/Sales_item.h"

using namespace std;

int main()
{
	istream_iterator<Sales_item> in_iter(cin), in_eof;
	vector<Sales_item> vec(in_iter, in_eof);

	sort(vec.begin(), vec.end(), [](const Sales_item &lhs, const Sales_item &rhs) { return lhs.isbn() < rhs.isbn(); });

	auto end = vec.begin();
	while (end != vec.end()) {
		auto beg = end;
		end = find_if(beg, vec.end(), [beg](const Sales_item &item) { return beg->isbn() != item.isbn(); } );
		
		Sales_item sum(beg->isbn());
		cout << accumulate(beg, end, sum) << endl;
	}

	return 0;
}
