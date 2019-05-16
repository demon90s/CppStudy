// 测试getline

#include <iostream>

using namespace std;

int main()
{
	// 输入测试：hello#world
	string str;

	// 截取hello
	getline(cin, str, '#');
	cout << str << endl;

	// 输出剩下的world
	getline(cin, str);
	cout << str << endl;

	// 输入CTRL+D，str被置为空字符串
	getline(cin, str);
	cout << str << endl;
	if (str.size() == 0)
		cout << "str is empty" << endl;

	return 0;
}
