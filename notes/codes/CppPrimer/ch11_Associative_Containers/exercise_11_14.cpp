// 练习11.14：扩展你在11.2.1节练习（第378页）中编写的孩子姓到名的map，添加
// 一个pair的vector，保存孩子的名和生日

// 练习11.7：定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子们的名。
// 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

using Family = map<string, vector<pair<string, string>>>; // 姓 - （名，生日）

void add_family(const string &family_name, Family &family_map)
{
	family_map[family_name].clear();
}

void add_child(const string &family_name, 
			const string &name, const string &birthday, 
			Family &family_map)
{
	auto it = family_map.find(family_name);
	if (it != family_map.end())
	{
		it->second.emplace_back(name, birthday);
	}
}

int main()
{
	Family family_map;

	add_family("Liu", family_map);
	add_family("Li", family_map);

	add_child("Liu", "Diwen", "1990-9-16", family_map);
	add_child("Liu", "Miemie", "2015-9-19", family_map);
	add_child("Li", "Meili", "1987-5-24", family_map);

	for (const auto &pair : family_map)
	{
		const auto &family_name = pair.first;
		cout << "family: " << family_name << endl;
		for (const auto &child : pair.second)
		{
			cout << child.first << " " << child.second << endl;
		}
		cout << "---------" << endl;
	}

	return 0;
}
