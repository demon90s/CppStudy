/*
 * 练习5.19：编写一段程序，使用do while循环重复地执行下述任务：首先提示
 * 用户输入两个string对象，然后挑出较短的那个并输出它。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
	do {
		string str1, str2;
		cout << "Enter two string:" << endl;
		cin >> str1 >> str2;

		if (cin) {
			if (str1.length() < str2.length())
				cout << str1 << " is shorter" << endl;
			else
				cout << str2 << " is shorter" << endl;
		}
	} while (cin); // 简单起见，输入CTRL+D结束循环

	return 0;
}
