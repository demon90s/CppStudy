// 练习17.22：重写你的电话号码程序，使之允许在号码的三个部分之间放置任意多个空白符。

// \s* 表示零个或多个空格，只需要修改匹配模式（即phone）即可。

#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool valid(const smatch &m)
{
	// 在一个合法的电话号码中，区号要么是完整括号包围的，要么完全没有括号。
	// 如果区号前有一个左括号
	if (m[1].matched)
	{
		// 则区号后必须有一个右括号，之后紧跟剩余号码或一个空格
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else
	{
		// 否则，区号后不能有右括号
		// 另外两个组成部分间的分隔符必须匹配
		return !m[3].matched && m[4].str() == m[6].str();
	}

	return false;
}

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?\\s*([-. ])?(\\d{3})\\s*([-. ])?(\\d{4})\\s*";

	/*
	 * e.g. (555)1234567
	 *      ^^  ^^  ^
	 *      12  35  7
	 *
	 * 1. (\\()? 表示区号部分可选的左括号
	 * 2. (\\d{3}) 表示区号
	 * 3. (\\))? 表示区号部分可选的右括号
	 * 4. ([-. ])? 表示区号部分可选的分隔符
	 * 5. (\\d{3}) 表示号码的下三位数字
	 * 6. ([-. ])? 表示可选的分隔符
	 * 7. (\\d{4}) 表示号码的最后四位数字
	 */

	regex r(phone);	// regex对象，用于查找我们的模式
	smatch m;
	string s;

	// 从输入文件中读取每条记录
	while (getline(cin, s))
	{
		bool matched = false;

		// 对每个匹配的电话号码
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			// 检查号码格式是否合法
			if (valid(*it))
				cout << "valid: " << it->str() << endl;
			else
				cout << "not valid: " << it->str() << endl;

			matched = true;
		}

		if (!matched)
		{
			cerr << "your input can not match phone number!" << endl;
		}
	}

	return 0;
}
