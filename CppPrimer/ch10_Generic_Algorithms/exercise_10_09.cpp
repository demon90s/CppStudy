// 练习10.9：实现你自己的elimDups。测试你的程序，分别在读取输入后、调用unique
// 后以及调用erase后打印vector的内容。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print(vector<string> &vec)
{
	for (const auto &i : vec)
		cout << i << " ";
	cout << endl;
}

void elimDups(vector<string> &words)
{
	// 按字典序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	// unique重排输出范围，使得每个单词只出现一次
	// 排列在范围的前部，返回指向不重复区域之后一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	print(words);
	// 使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
	print(words);
}

int main()
{
	vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
	print(words);
	elimDups(words);

	return 0;
}
