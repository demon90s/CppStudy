// 练习11.23：11.2.1节练习（第378页）中的map以孩子的姓为关键字，保存他们的名的
// vector，用multimap重写此map。

// 练习11.7：定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子们的名。
// 编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

using Family = multimap<string, string>;

void add_child(const string &family_name, const string &name, Family &family_map)
{
	family_map.insert({family_name, name});
}

int main()
{
	Family family_map;

	add_child("Liu", "Diwen", family_map);
	add_child("Liu", "Miemie", family_map);
	add_child("Li", "Meili", family_map);

	for (const auto &pair : family_map)
	{
		cout << "family: " << pair.first << " " << pair.second << endl;
	}

	return 0;
}
