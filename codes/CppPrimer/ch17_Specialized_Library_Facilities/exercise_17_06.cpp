// 练习17.6：重写findBook, 不使用tuple或pair。

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../ch07_Classes/example_Sales_data/Sales_data.h"

using namespace std;

// matches有三个成员：一家书店的索引和两个指向书店vector中元素的迭代器 

struct matches
{
	vector<Sales_data>::size_type index;
	vector<Sales_data>::const_iterator it_beg;
	vector<Sales_data>::const_iterator it_end;
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

// file保存每家书店的销售记录
// findBook返回一个vector，每家销售了给定书籍的书店在其中都有一项
vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> res;

	// 对每家书店，查找与给定书籍匹配的记录范围（如果存在的话）
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		// 查找具有相同ISBN的Sales_data范围（book隐式转换成一个Sales_data对象）
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);

		if (found.first != found.second) // 此书店销售了给定书籍
			// 记住此书店的索引及匹配的范围
		{
			auto index = (size_t)(it - files.cbegin()); // convert to size_t to ignore warning
			matches m = {index, found.first, found.second};
			res.push_back(m);
		}
	}

	return res;
}

void reportResult(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
	string s; // 要找的书
	while (in >> s) {
		auto trans = findBook(files, s);	// 销售了这本书的书店
		if (trans.empty()) {
			cout << s << " not found in any stores" << endl;
			continue;
		}

		for (const auto &store : trans)		// 对每家销售了给定书籍的书店
			// get<n>返回store中tuple的指定的成员
			os << "store " << store.index << " sales: "
			   << accumulate(store.it_beg, store.it_end, Sales_data(s))
			   << endl;
	}
}

int main()
{
	ifstream ifs("../data/book_sales");
	if (!ifs)
	{
		cerr << "open file failed" << endl;
		return -1;
	}

	// 就测试一个书店
	vector<vector<Sales_data>> files;
	files.resize(1);

	{
		Sales_data tmp;
		while (ifs >> tmp)
		{
			files[0].push_back(tmp);
		}

		sort(files[0].begin(), files[0].end(), compareIsbn);
	}

	reportResult(cin, cout, files);

	return 0;
}
