#include <iostream>
#include <string>
#include <set>

using namespace std;

// 将自定义数据结构对象插入set的方法
// 使用如下方法，则相同的 score 不会重复插入

struct Item
{
	int id;
	int score;
};

bool operator<(const Item &lhs, const Item &rhs)
{
	return lhs.score < rhs.score;
}

bool compareItem(const Item &lhs, const Item &rhs)
{
	return lhs.score < rhs.score;
}

struct CompareItemObj
{
	bool operator()(const Item &lhs, const Item &rhs) const
	{
		return lhs.score < rhs.score;
	}
};

template<typename T>
void test_output(T &item_set)
{
	item_set.insert({1, rand() % 10});
	item_set.insert({2, rand() % 10});
	item_set.insert({3, rand() % 10});

	cout << "----------------------\n";
	for (const auto &item : item_set)
	{
		cout << "id: " << item.id << " score: " << item.score << endl;;
	}
	cout << "----------------------\n";
}

int main()
{
	set<Item> item_set1;	
	test_output(item_set1);

	set<Item, bool(*)(const Item&, const Item&)> item_set2([](const Item &lhs, const Item &rhs) { return lhs.score < rhs.score; });
	test_output(item_set2);

	set<Item, bool(*)(const Item&, const Item&)> item_set3(compareItem);
	test_output(item_set3);

	set<Item, CompareItemObj> item_set4;
	test_output(item_set4);

	return 0;
}
