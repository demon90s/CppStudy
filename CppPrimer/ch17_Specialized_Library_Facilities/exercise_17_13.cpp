// 练习17.13：编写一个整型对象，包含真假测验的正确答案。使用它来为前两题中的
// 数据结构生成测验成绩。

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
	constexpr int Q_COUNT = 10;

	QA<Q_COUNT> qa("1111100000");

	// 假定一题10分
	int score = 0;

	bitset<Q_COUNT> real_answer(0xFFFFFFFF);	// 这个整型对象就是0xFFFFFFFF，多余的位被舍弃

	for (int i = 0; i < Q_COUNT; ++i)
	{
		if (qa.result_bitset[i] == real_answer[i])
		{
			score += 10;
		}
	}

	cout << "got score: " << score << endl;

	return 0;
}
