// 练习17.23：编写查找邮政编码的正则表达式。一个美国邮政编码可以由五位或九位数
// 字组成。前五位数字和后四位数字之间可以用一个短横线分隔。

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string pattern = "[0-9]{5}(-[0-9]{4})?"; // 参考；https://www.ibm.com/developerworks/cn/java/j-validating/
	regex r(pattern);

	cout << "input number: " << endl;

	string number;
	if (cin >> number)
	{
		for (sregex_iterator it(number.begin(), number.end(), r), end_it; it != end_it; ++it)
		{
			cout << it->str() << endl;
		}
	}

	return 0;
}
