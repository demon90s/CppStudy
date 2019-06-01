// 练习17.11：定义一个数据结构，包含一个整型对象，记录一个包含10个问题的真假
// 测验的解答。如果测验包含100道题，你需要对数据结构做出什么改变（如果需要的话）？

// 直接修改bitset的二进制位的个数即可。或者把结构体定义成一个模板，模板参数是一个
// 非类型参数，指出问题的个数，同时用于指出bitset的二进制位的个数。

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

struct QA
{
	bitset<128> result_bitset;
};

template <unsigned N>
struct QA2
{
	QA2() {}
	QA2(const char *bits) : result_bitset(bits) {}

	bitset<N> result_bitset;
};

int main()
{
	QA2<10> qa("0000011111");
	cout << qa.result_bitset.to_string() << endl;

	return 0;
}
