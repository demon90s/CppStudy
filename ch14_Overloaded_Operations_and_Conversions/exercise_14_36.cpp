// 练习14.36：使用前一个练习定义的类读取标准输入，将每一行保存为vector的一个
// 元素。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ReadString
{
public:
	ReadString(istream &is) : m_is(is) {}
	string operator()() const
	{
		string line;
		if (getline(m_is, line))
			return line;
		return "";
	}

private:
	istream &m_is;
};

int main()
{
	vector<string> vec;
	ReadString reader(cin);
	string line;
	while ((line = reader()).length() > 0) {
		vec.emplace_back(line);
	}

	for_each(vec.cbegin(), vec.cend(), [](const string &line) { cout << line << "\n"; });

	return 0;
}
