// 练习14.39：修改上一题的程序令其报告长度在1至9之间的单词有多少个、长度在10
// 以上的单词又有多少个？

// 练习14.38：编写一个类令其检查某个给定的string对象的长度是否与一个阙值相等。
// 使用该对象编写程序，统计并报告在输入文件中长度为1的单词有多少个、长度为2
// 的单词有多少个、....、长度为10的单词又有多少个。

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class SizeCmp1
{
public:
	SizeCmp1(size_t lower, size_t upper) : m_lower(lower), m_upper(upper) {}
	bool operator()(size_t len) const { return len >= m_lower && len < m_upper; }

private:
	size_t m_lower;
	size_t m_upper;
};

class SizeCmp2
{
public:
	SizeCmp2(size_t lower) : m_lower(lower) {}
	bool operator()(size_t len) const { return len >= m_lower; }

private:
	size_t m_lower;
};

int main()
{
	string file_name;
	cin >> file_name;

	ifstream ifs(file_name);
	if (!ifs.is_open())
	{
		cerr << "open file fail" << endl;
		return -1;
	}

	string line;
	string word;
	SizeCmp1 cmper1(1, 9);
	SizeCmp2 cmper2(10);
	size_t n1_9 = 0;
	size_t n10 = 0;

	while (getline(ifs, line))
	{
		istringstream iss(line);
		while (iss >> word)
		{
			if (cmper1(word.length()))
			{
				++n1_9;
			}

			if (cmper2(word.length()))
			{
				++n10;
			}
		}
	}

	cout << "number of len in 1-9: " << n1_9 << endl;
	cout << "number of len >= 10 : " << n10 << endl;

	return 0;
}
