// 练习17.27：编写程序，将九位数字邮政编码的格式转换为ddddd-dddd。

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string pattern = "([0-9]{5})-([0-9]{4})?"; // 参考；https://www.ibm.com/developerworks/cn/java/j-validating/
	regex r(pattern);	// 寻找模式所用的regex对象

	string s;
	string fmt = "$1-$2";	

	cout << "input number: ";
	cin >> s;
	cout << regex_replace(s, r, fmt) << endl;

	return 0;
}
