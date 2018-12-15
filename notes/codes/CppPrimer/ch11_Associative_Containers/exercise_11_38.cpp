// 练习11.38：用unordered_map重写单词计数程序（参见11.1节，第375页）和单词
// 转换程序（参见11.3.6节，第391页）。

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	// 统计每个单词在输入中出现的次数
	unordered_map<string, size_t> word_count;	// string到size_t的空map
	string word;
	while (cin >> word)
		++word_count[word];	// 提取word的计数器并将其加1
	
	for (const auto &w : word_count) // 对map中的每个元素
		// 打印结果
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
