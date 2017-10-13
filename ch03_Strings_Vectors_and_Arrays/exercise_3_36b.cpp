/*
 * 练习3.36：编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
 */

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> vec1 = {1, 2, 3};
	vector<int> vec2 = {1, 2, 3};

	bool is_equal = (vec1 == vec2);

	if (is_equal)
		cout << "Is equal" << endl;
	else
		cout << "Is not equal" << endl;

	return 0;
}
