// 练习10.42：使用list代替vector重新实现10.2.3节（第343页）中的去除重复
// 单词的程序。

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void elimDups(list<string> &words)
{
	words.sort();
	words.unique();
}

int main()
{
	list<string> words{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

	elimDups(words);

	for (const auto &w : words)
		cout << w << " ";
	cout << endl;

	return 0;
}
