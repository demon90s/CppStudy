/*
 * 练习3.4：编写一段程序读入两个字符串，比较其是否相等并输出结果。如果不想等，输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
 */

#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1, str2;

	cout << "Enter two strings:" << endl;
	cin >> str1 >> str2;

	if (str1 == str2)
		cout << "Equal" << endl;
	else {
		cout << "Not equal" << endl;
		
		if (str1 > str2)
			cout << str1 << endl;
		else
			cout << str2 << endl;
	}

	

	return 0;
}
