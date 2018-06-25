// 练习9.13：如何从一个list<int>初始化一个vector<double>？从一个vector<int>
// 又该如何创建？编写代码验证你的答案。

#include <iostream>
#include <list>
#include <vector>

using namespace std;

#define print_vec(vec)\
do {\
	cout << #vec << ": ";\
	for (auto i : vec)\
		cout << i << " ";\
	cout << endl;\
} while (0)

void func_list_to_vector()
{
	list<int> ilst = {1, 2, 3};
	vector<double> dvec(ilst.begin(), ilst.end());
	print_vec(dvec);
}

void func_ivec_to_dvec()
{
	vector<int> ivec = {1, 2, 3};
	vector<double> dvec(ivec.begin(), ivec.end());
	print_vec(dvec);
}

int main()
{
	func_list_to_vector();
	func_ivec_to_dvec();
	return 0;
}
