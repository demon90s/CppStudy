// 练习11.32：使用上一题定义的multimap编写一个程序，按字典序打印作者列表和
// 他们的作品。

// 练习11.31：编写程序，定义一个作者及其作品的multimap。使用find在multimap
// 中查找一个元素并用erase删除它。确保你的程序在元素不在map中时也能正常运行。

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> authors = {
		{"Liudiwen", "GameNoob"},
		{"Liudiwen", "CppNoob"},
		{"Lee", "Hehe"}
	};

	map<string, set<string>> ordered_authors;

	for (const auto &pair : authors)
	{
		ordered_authors[pair.first].insert(pair.second);
	}

	for (const auto &pair : ordered_authors)
	{
		cout << pair.first << ":";
		for (const auto &books : pair.second)
		{
			cout << " " << books;
		}
		cout << endl;
	}

	return 0;
}
