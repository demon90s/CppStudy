// 练习14.40：重新白那些10.3.2节（第349页）的biggiest函数，使用函数对象类替换其中的
// lambda表达式。

// 练习10.16：使用lambda编写你自己版本的biggies。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Cmp1
{
public:
	bool operator()(const string &a, const string &b) const
	{
		return a.size() < b.size();
	}
};

class Cmp2
{
public:
	Cmp2(size_t sz) : m_sz(sz) {}
	bool operator()(const string &a) const
	{
		return a.size() >= m_sz;
	}

private:
	size_t m_sz;
};

class Printer
{
public:
	void operator()(const string &s) const
	{
		cout << s << " ";
	}
};

void biggest(vector<string> &words, vector<string>::size_type sz)
{
	// 按长度排序
	stable_sort(words.begin(), words.end(), Cmp1());

	// 获取一个迭代器，指向第一个满足size() >= sz的元素
	auto wc = find_if(words.begin(), words.end(), Cmp2(sz));

	// 计算满足size >= sz的元素的数目
	auto count = words.end() - wc;
	cout << count << endl;

	// 打印长度大于等于sz的单词
	for_each(wc, words.end(), Printer());
	cout << endl;
}

int main()
{
	vector<string> words = { "hello", "father", "my", "ops", "yours", "everything" };
	vector<string>::size_type sz = 5;

	biggest(words, sz);

	return 0;
}
