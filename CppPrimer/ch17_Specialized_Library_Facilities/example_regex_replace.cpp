// example: 使用regex_replace（p657）

// ./example_regex_replace < ../data/person_numbers.txt

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);	// 寻找模式所用的regex对象

	string s;
	string fmt = "$2.$5.$7";	// 将号码格式改为ddd.ddd.dddd

	// 从输入文件中读取每条记录
	while (getline(cin , s))
	{
		cout << regex_replace(s, r, fmt) << endl;
	}

	return 0;
}
