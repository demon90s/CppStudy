// example: 逗号运算符（p140）

/*
 * 逗号运算符的使用例子，逗号运算符经常被用在for循环当中
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	vector<int> ivec(10);

	vector<int>::size_type cnt = ivec.size();
	// 将把从size到1的值赋给ivec的元素
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
	{
		ivec[ix] = cnt;
	}

	//----------------------------------------
	
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}
