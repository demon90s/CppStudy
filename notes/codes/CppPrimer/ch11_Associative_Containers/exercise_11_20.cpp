// 练习11.20：重写11.1节练习（第376页）的单词计数程序，使用insert代替下标
// 操作。你认为哪个程序更容易编写和阅读？解释原因。

// 使用下标的版本更容易编写和阅读，原因在于返回的ret类型过于复杂。

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	// 统计每个单词在输入中出现的次数
	map<string, size_t> word_count;	// string到size_t的空map
	string word;
	while (cin >> word)
	{
		auto ret = word_count.insert({word, 1});
		if (!ret.second)
		{
			// 插入失败，则累加
			++ret.first->second;
		}
	}
	
	for (const auto &w : word_count) // 对map中的每个元素
		// 打印结果
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
