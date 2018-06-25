/*
 * 练习6.17：编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部
 * 改成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？
 */

/*
 * 第一个函数使用const string&，第二个string&，这是因为判断是否有大写字母不需要改写字符串。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

bool has_upper_char(const string &s)
{
	for (auto c : s) {
		if (isupper(c))
			return true;
	}
	return false;
}

void str_tolower(string &s)
{
	for (auto &c : s)
		c = tolower(c);
}

int main()
{
	// test
	string str = "Hello World";

	has_upper_char(str) ? cout << "Has upper character" << endl : cout << "Has not upper character" << endl;
	str_tolower(str);
	
	cout << str << endl;

	return 0;
}
