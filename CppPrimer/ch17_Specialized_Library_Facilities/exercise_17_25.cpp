// 练习17.25：重写你的电话号码程序，使之只输出每个人的第一个电话号码。

// ./exercise_17_25 < ../data/person_numbers.txt

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);	// 寻找模式所用的regex对象

	smatch result;
	string s;

	while (getline(cin, s))
	{
		if (regex_search(s, result, r))
		{
			cout << result.str() << endl;
		}
	}

	return 0;
}
