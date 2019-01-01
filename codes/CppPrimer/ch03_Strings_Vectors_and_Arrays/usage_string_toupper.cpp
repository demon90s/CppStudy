// 把字符串改写为大写字母的形式

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s("Hello World");
	// 转换成大写形式
	for (auto &c : s)
		c = toupper(c);	// c是一个引用，因此赋值语句将改变s中字符的值
	cout << s << endl;

	return 0;
}
