// 测试操作两个序列的算法(p339)
// 如果背叛了重要的假设，测试结果：结果没有崩溃
// 但这是严重的错误，见p340，关键概念：迭代器参数

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec1{1, 2, 3, 4, 5, 6, 7};
	vector<int> vec2{1, 2};

	cout << equal(vec1.cbegin(), vec1.cend(), vec2.cbegin()) << endl;

	return 0;
}
