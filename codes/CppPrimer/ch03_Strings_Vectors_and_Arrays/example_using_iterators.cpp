// example: 迭代器运算符（p96）
// 把string对象的第一个字母改为大写形式

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string s("some string");
	if (s.begin() != s.end()) {	// 确保s非空
		auto it = s.begin();	// it表示s的第一个字符
		*it = toupper(*it);		// 将当前字符改写成大写形式
	}

	cout << s << endl;

	return 0;
}
