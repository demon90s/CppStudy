/*
 * 练习9.11：为6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个
 * vector包含什么值。
 */

#include <iostream>
#include <vector>

using namespace std;

#define print_vec(vec)\
do {\
	cout << #vec << ": ";\
	for (auto i : vec)\
		cout << i << " ";\
	cout << endl;\
} while (0)

int main()
{
	vector<int> ivec1;	// 空vector
	print_vec(ivec1);

	vector<int> ivec2 = {1, 2, 3};	// 1 2 3
	print_vec(ivec2);

	vector<int> ivec3 = ivec2;		// 1 2 3
	print_vec(ivec3);

	vector<int> ivec4(ivec3.begin(), ivec3.end());	// 1 2 3
	print_vec(ivec4);

	vector<int> ivec5(5);			// 0 0 0 0 0
	print_vec(ivec5);

	vector<int> ivec6(6, 6);		// 6 6 6 6 6 6
	print_vec(ivec6);

	return 0;
}
