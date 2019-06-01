// 练习11.8：编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用
// set的优点是什么？

// 用set代码更简单，执行效率更高

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v;
	string word;

	while (cin >> word)
	{
		if (find(v.begin(), v.end(), word) == v.end())
		{
			v.push_back(word);
		}
	}

	for (const auto &w : v)
	{
		cout << w << " ";
	}
	cout << endl;

	return 0;
}
