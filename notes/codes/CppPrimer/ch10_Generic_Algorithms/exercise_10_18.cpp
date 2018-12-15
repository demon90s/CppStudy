// 练习10.18：重写biggies，用partition代替find_if。我们在10.3.1节练习10.13
// （第345页）中介绍了partition算法。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void biggest(vector<string> &words, vector<string>::size_type sz)
{
	// 获取一个迭代器，指向第一个满足size() >= sz的元素
	auto wc = partition(words.begin(), words.end(), [sz](const string &a)
						{ return a.size() < sz; } );

	// 计算满足size >= sz的元素的数目
	auto count = words.end() - wc;
	cout << count << endl;

	// 打印长度大于等于sz的单词
	for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> words = { "hello", "father", "my", "ops", "yours", "everything" };
	vector<string>::size_type sz = 5;

	biggest(words, sz);

	return 0;
}
