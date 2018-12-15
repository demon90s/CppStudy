// example: 指定或使用正则表达式时的错误（p648）

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	try {
		// 错误，alnum漏掉了右括号，构造函数会抛出异常
		regex r("[[:alnum:]", regex::icase);
	}
	catch (regex_error e)
	{
		cout << e.what() << "\ncode: " << e.code() << endl;
	}

	return 0;
}
