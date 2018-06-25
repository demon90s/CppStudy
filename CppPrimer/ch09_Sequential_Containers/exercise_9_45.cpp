// 练习9.45：编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如
// Mr.或Ms.）和后缀（如Jr.或III）的字符串。使用迭代器及insert和append函数将
// 前缀和后缀添加到给定的名字中，将生成新string返回。

#include <iostream>
#include <string>

using namespace std;

string func(const string &s, const string &prefix, const string &suffix)
{
	string str = s;
	str.insert(str.begin(), prefix.begin(), prefix.end());
	str.append(suffix.begin(), suffix.end());

	return str;
}

int main()
{
	string s = "Joe";

	cout << func(s, "Mr.", "III") << endl;

	return 0;
}
