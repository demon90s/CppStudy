/*
 * 练习3.5：编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。
 */

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string word;
	string result_str;
	while (cin >> word)
		result_str += word;

	cout << result_str << endl;

	return 0;
}
