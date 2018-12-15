// 练习11.4：扩展你的程序，忽略大小写和标点。例如，"example.", "example,"和"Example"
// 应该递增相同的计数器。

#include <cctype>

#include <iostream>
#include <string>
#include <map>

using namespace std;

void fix(string &word)
{
	string s;
	for (auto c : word)
	{
		if (!ispunct(c))
		{
			s += tolower(c);
		}
	}
	word = s;
}

int main()
{
	// 统计每个单词在输入中出现的次数
	map<string, size_t> word_count;	// string到size_t的空map
	string word;
	while (cin >> word) {
		fix(word);
		++word_count[word];	// 提取word的计数器并将其加1
	}
	
	for (const auto &w : word_count) // 对map中的每个元素
		// 打印结果
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
