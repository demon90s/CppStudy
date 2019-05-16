/*
 * c.lower_bound(val) 返回 val 的第一个可安插位置，也就是“元素值>=val”的第一个元素位置
 * c.upper_bound(val) 返回 val 的最后一个可安插位置，也就是“元素值>val”的第一个元素位置
 * c.equal_range(val) 返回 val 可被安插的第一个可最后一个位置，也就是“元素值==val”的元素区间，如果不存在同值元素，返回的 pair 的 first == second
 */

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> c;

	c.insert(1);
	c.insert(2);
	c.insert(3);
	c.insert(4);
	c.insert(5);
	c.insert(6);

	cout << "lower_bound(3): " << *c.lower_bound(3) << endl; // 3
	cout << "upper_bound(3): " << *c.upper_bound(3) << endl; // 4
	cout << "equal_range(3): " << *c.equal_range(3).first << " " // 3
				   << *c.equal_range(3).second << endl; // 4

	cout << endl;
	cout << "lower_bound(5): " << *c.lower_bound(5) << endl; // 5
	cout << "upper_bound(5): " << *c.upper_bound(5) << endl; // 6
	cout << "equal_range(5): " << *c.equal_range(5).first << " " // 5
				   << *c.equal_range(5).second << endl; // 6
}


