// example: const_cast和重载（p209）

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 比较两个string对象的长度，返回较短的那个引用
const string &shorterString(const string &s1, const string &s2)
{
	cout << "Called this function: " << "const string &shorterString(const string &s1, const string &s2)" << endl;

	return s1.size() <= s2.size() ? s1 : s2;
}

// 重载
string &shorterString(string &s1, string &s2)
{
	cout << "Called this function: " << "string &shorterString(string &s1, string &s2)" << endl;

	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int main()
{
	string s1 = "hello";
	string s2 = "hi";

	cout << shorterString(s1, s2) << endl; // 调用顺序 --> 非const版本的 --> const版本的

	return 0;
}
