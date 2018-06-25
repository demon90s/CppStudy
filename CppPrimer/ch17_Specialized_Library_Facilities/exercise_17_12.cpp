// 练习17.12：使用前一题中的数据结构，编写一个函数，它接受一个问题编号和一个表示
// 真假解答的值，函数根据这两个参数更新测验的解答。

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

template <unsigned N>
struct QA
{
	QA() {}
	QA(const char *bits) : result_bitset(bits) {}

	void Answer(unsigned i, bool is_right);

	bitset<N> result_bitset;
};

template <unsigned N> inline
void QA<N>::Answer(unsigned i, bool is_right)
{
	if (i >= 0 && i < N)
		result_bitset[i] = is_right;
}

int main()
{
	QA<10> qa;
	qa.Answer(0, true);

	cout << qa.result_bitset.to_string() << endl;

	return 0;
}
