// 练习9.46：重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。

#include <iostream>

using namespace std;

string func(const string &s, const string &prefix, const string &suffix)
{
	string str = s;
	str.insert(0, prefix);
	str.insert(str.size(), suffix);

	return str;
}

int main()
{
	string s = "Joe";

	cout << func(s, "Mr.", "III") << endl;

	return 0;
}
