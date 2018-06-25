// 练习10.25：在10.3.2节（第349页）的练习中，编写了一个使用partition的biggies
// 版本。使用check_size和bind重写此函数。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

void biggest(vector<string> &words, vector<string>::size_type sz)
{
	// 获取一个迭代器，指向第一个满足size() >= sz的元素
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz) );

	// 计算满足size >= sz的元素的数目
	auto count = wc - words.begin();
	cout << count << endl;

	// 打印长度大于等于sz的单词
	for_each(words.begin(), wc, [](const string &s) { cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> words = { "hello", "father", "my", "ops", "yours", "everything" };
	vector<string>::size_type sz = 5;

	biggest(words, sz);

	return 0;
}
