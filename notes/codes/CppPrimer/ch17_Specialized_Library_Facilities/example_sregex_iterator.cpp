// example: 匹配与Regex迭代器类型（p650）

#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 使用sregex_iterator
void func1()
{
	string test_str = "receipt freind theif receive";

	// 查找前一个字符不是c的字符串ci
	string pattern("[^c]ei");

	// 我们想要包含pattern的单词的全部内容
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);	// 在进行匹配时将忽略大小写

	// 它将反复调用regex_search来寻找文件中的所有匹配
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; it != end_it; ++it)
	{
		cout << it->str() << endl;	// 匹配的单词
	}
}

// 使用匹配数据
void func2()
{
	string test_str = "receipt freind theif receive";

	// 查找前一个字符不是c的字符串ci
	string pattern("[^c]ei");

	// 我们想要包含pattern的单词的全部内容
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern, regex::icase);	// 在进行匹配时将忽略大小写

	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; it != end_it; ++it)
	{
		auto pos = it->prefix().length();	// 前缀的大小
		pos = pos > 40 ? pos - 40 : 0;		// 我们想要最多40个字符
		cout << it->prefix().str().substr(pos) // 前缀最后一部分
		     << "\n\t\t>>> " << it->str() << " <<<\n"	// 匹配的单词
			 << it->suffix().str().substr(0, 40)	// 后缀的第一部分
			 << endl;
	}
}

int main()
{
	//func1();
	func2();

	return 0;
}
