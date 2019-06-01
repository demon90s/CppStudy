# 向set中插入自定义类型对象

set中的元素必须有序，所以必须为自定义类型定义比较的方法，可以使用下面这些方法：

1. 使用自定义operator<运算符

2. 使用自定义比较函数

3. 使用可调用对象（lambda表达式或重载了operator()的类）

---

## 代码案例

```c++
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
```
