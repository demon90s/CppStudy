// example: sort和unique函数，消除重复单词（p343）

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
	// 按字典序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	// unique重排输出范围，使得每个单词只出现一次
	// 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
}

int main()
{
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	elimDups(words);

	for (const auto &w : words)
		cout << w << " ";
	cout << endl;

	return 0;
}
