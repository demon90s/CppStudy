// example: 使用引用形参返回额外信息（p189）

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 返回s中c第一次出现的位置索引
// 引用形参occurs负责统计c出现的总次数
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();	// 第一次出现的位置（如果有的话）
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;	// 记录c第一次出现的位置
			++occurs;
		}
	}
	return ret;	// 出现次数通过occurs隐式地返回
}

int main()
{
	string::size_type occurs;
	auto index = find_char("hello world", 'o', occurs);

	if (occurs > 0) {
		cout << "o occurs " << occurs << " times" << endl;
		cout << "first occurs index: " << index << endl;
	}

	return 0;
}
