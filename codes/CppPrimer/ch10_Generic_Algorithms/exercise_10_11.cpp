// 练习10.11：编写程序，使用stable_sort和isShorter将传递给你的elimDups
// 版本的vector排序。打印vector的内容，验证你的程序的正确性。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
	// 按字典序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	// unique重排输出范围，使得每个单词只出现一次
	// 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());

	stable_sort(words.begin(), words.end(), isShorter);
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
