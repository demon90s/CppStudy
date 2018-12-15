// example: 内联函数可避免函数调用开销（p213）

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// 内联版本：寻找两个string对象中较短的那个
inline const string &
shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}

int main()
{
	cout << shorterString("Hello", "Hi") << endl;

	return 0;
}
