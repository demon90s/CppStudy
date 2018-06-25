/*
 * 编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
 */

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
	const char *str1 = "hello";
	const char *str2 = "hi";

	auto res = strcmp(str1, str2);

	if (0 == res)
		cout << "str1 == str2" << endl;
	else if (res > 0)
		cout << "str1 > str2" << endl;
	else
		cout << "str1 < str2" << endl;

	return 0;
}
