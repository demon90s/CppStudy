// 练习14.38：编写一个类令其检查某个给定的string对象的长度是否与一个阙值相等。
// 使用该对象编写程序，统计并报告在输入文件中长度为1的单词有多少个、长度为2
// 的单词有多少个、....、长度为10的单词又有多少个。

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class SizeCmp
{
public:
	SizeCmp(size_t size = 0) : m_size(size) {}
	bool operator()(size_t sz) const { return m_size == sz; }

	void SetSize(size_t size) { m_size = size; }

private:
	size_t m_size;
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

	constexpr int SZ_LIST_COUNT = 10;
	size_t sz_count_list[SZ_LIST_COUNT] = {0};

	string line;
	string word;
	SizeCmp size_cmper;

	while (getline(ifs, line))
	{
		istringstream iss(line);
		while (iss >> word)
		{
			for (size_t sz = 0; sz < SZ_LIST_COUNT; ++sz)
			{
				size_cmper.SetSize(sz + 1);
				if (size_cmper(word.length()))
				{
					++sz_count_list[sz];
					break;
				}
			}
		}
	}

	for (size_t sz = 0; sz < SZ_LIST_COUNT; ++sz)
	{
		cout << sz + 1 << " count: " << sz_count_list[sz] << endl;
	}

	return 0;
}
