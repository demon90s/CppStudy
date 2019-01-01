// 练习17.18：修改你的程序，忽略包含“ei”但并非拼写错误的单词，如“albeit”和
// "neighbor"

// my note：如何才能判断并非拼写错误呢？我尚不知，为了方便起见，就用一个set保存这样的单词了。

#include <iostream>
#include <regex>
#include <set>
#include <string>

using namespace std;

set<string> valid_string_set{"albeit", "neighbor"};

int main()
{
	string pattern("[^c]ei");

	// 我们需要包含pattern的整个单词
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";

	regex r(pattern);	// 构造一个用于查找模式的regex
	smatch results;		// 定义一个对象保存结果

	// 定义一个string保存与模式匹配和不匹配的文本
	string test_str = "receipt freind theif receive albeit neighbor";

	for (sregex_iterator it(test_str.begin(), test_str.end(), r), it_end; it != it_end; ++it)
	{
		if (valid_string_set.count(it->str()) == 0)
			cout << it->str() << endl;
	}

	return 0;
}
