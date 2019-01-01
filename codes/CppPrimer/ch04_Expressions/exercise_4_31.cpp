/*
 * 练习4.31：本节的程序使用了前置版本的递增运算符和递减运算符，解释为什么要用前置版本而不用后置版本。要想使用后置版本的递增递减运算符需要做哪些改动？使用后置版本重写本节的程序。
 */

/*
 * 因为后置版本需要保留一份原始对象的副本将其作为运算结果，而前置不用。见p132。
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
	for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--) // 仅在这里做改动
	{
		ivec[ix] = cnt;
	}

	//----------------------------------------
	
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;

	return 0;
}
