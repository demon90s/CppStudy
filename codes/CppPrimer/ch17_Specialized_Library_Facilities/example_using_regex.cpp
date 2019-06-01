// example: 使用正则表达式库（p646）

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	// 查找不在字符c之后的字符串ei
	string pattern("[^c]ei");

	// 我们需要包含pattern的整个单词
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	regex r(pattern);	// 构造一个用于查找模式的regex
	smatch results;		// 定义一个对象保存结果

	// 定义一个string保存与模式匹配和不匹配的文本
	string test_str = "receipt freind theif receive";

	// 用r在test_str中查找与pattern匹配的子串
	if (regex_search(test_str, results, r))		// 如果有匹配子串
		cout << results.str() << endl;			// 打印匹配的单词

	return 0;
}
