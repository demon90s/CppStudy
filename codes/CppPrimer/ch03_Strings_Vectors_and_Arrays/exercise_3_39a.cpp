/*
 * 编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
	string str1 = "hello";
	string str2 = "hi";

	if (str1 == str2)
		cout << "str1 == str2" << endl;
	else if (str1 > str2)
		cout << "str1 > str2" << endl;
	else
		cout << "str1 < str2" << endl;

	return 0;
}
