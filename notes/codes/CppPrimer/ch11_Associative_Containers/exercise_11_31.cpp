// 练习11.31：编写程序，定义一个作者及其作品的multimap。使用find在multimap
// 中查找一个元素并用erase删除它。确保你的程序在元素不在map中时也能正常运行。

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	multimap<string, string> authors = {
		{"Liudiwen", "CppNoob"},
		{"Liudiwen", "GameNoob"},
		{"Lee", "Hehe"}
	};

	const char *key = "Liudiwen";

	auto it = authors.find(key);

	while (it != authors.end())
	{
		it = authors.erase(it);
	}

	for (const auto &pair : authors)
	{
		cout << pair.first << " " << pair.second << endl;
	}

	return 0;
}
