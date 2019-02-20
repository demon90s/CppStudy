/*
 * 运行期指定排序规则
 * 方法，采用同样的定义式，如：std::set<int, compare>
 * compare 是一个可调用对象类型，也叫比较准则，其 operator() 操作符决定了具体的排序规则
 *
 * 因此， set 的类型是一致的，但规则却可以动态地改变。
 *
 * c.value_comp() 返回的是比较准则（comparison criterion）
 */

#include <iostream>
#include <set>

using namespace std;

template<typename T>
void PrintContainer(const T &coll, const char* prefix)
{
	cout << prefix;
	for (const auto &i : coll)
		cout << i << " ";
	cout << endl;
}

// type for runtime sorting criterion
class RuntimeCmp {
public:
	enum cmp_mode {normal, reverse};

private:
	cmp_mode mode;

public:
	// constructor for sorting criterion
	// - default criterion uses value normal
	RuntimeCmp(cmp_mode m = normal) : mode(m) {
	}

	// comparision of elements
	// - member function for any element type
	template<typename T>
	bool operator()(const T& t1, const T& t2) const {
		return mode == normal ? t1 < t2 : t2 < t1;
	}

	// comparision of sorting criteria
	bool operator==(const RuntimeCmp& rc) const {
		return mode == rc.mode;
	}
};

// type of a set that uses this sorting criterion
typedef set<int, RuntimeCmp> IntSet;

int main()
{
	// create, fill and print set with normal element order
	// - uses default sorting criterion
	IntSet coll1 = {4, 7, 5, 1, 6, 2, 5};
	PrintContainer(coll1, "coll1: ");

	// create sorting criterion with reverse element order
	RuntimeCmp reverse_order(RuntimeCmp::reverse);
	IntSet coll2(reverse_order);
	coll2 = {4, 7, 5, 1, 6, 2, 5};
	PrintContainer(coll2, "coll2: ");

	// assign elements AND sorting criterion
	coll1 = coll2;
	coll1.insert(3);
	PrintContainer(coll1, "coll1: ");

	// just to make sure ...
	if (coll1.value_comp() == coll2.value_comp()) {
		cout << "coll1 and coll2 have the same sorting criterion"
			<< endl;
	}
	else {
		cout << "coll1 and coll2 have a different sorting criterion"
			<< endl;
	}

	return 0;
}
