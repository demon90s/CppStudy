/*
 * 练习3.25：3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序并实现完全相同的功能。
 */

/*
 * 42 65 95 100 39 67 95 76 88 76 83 92 76 93
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	// 以10分为一个分数段统计成绩的数量：0~9, 10~19,...,90~99, 100
	vector<unsigned> scores(11, 0);		// 11个分数段，全都初始化为0

	unsigned grade;
	while (cin >> grade) {		// 读取成绩
		if (grade <= 100) {		// 只处理有效成绩
			*(scores.begin() + grade / 10) += 1;
		}
	}

	for (auto i : scores)
		cout << i << " ";
	cout << endl;

	return 0;
}
