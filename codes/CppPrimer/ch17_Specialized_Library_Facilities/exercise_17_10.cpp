// 练习17.10：使用序列1、2、3、5、8、13、21初始化一个bitset，将这些位置置位。
// 对另一个bitset进行默认初始化，并编写一小段程序将其恰当的位置位。

#include <iostream>
#include <bitset>
#include <string>
#include <set>
#include <vector>

using namespace std;

static const int MAX_BIT_CNT = 32;

void func1()
{
	std::string str;
	std::set<int> hit_bits{1, 2, 3, 5, 8, 13, 21};
	for (int i = 0; i < MAX_BIT_CNT; ++i)
	{
		if (hit_bits.count(MAX_BIT_CNT - 1 - i) > 0) // 下标高的对应低位
		{
			str += '1';
		}
		else
		{
			str += '0';
		}
	}

	bitset<MAX_BIT_CNT> bv(str);

	cout << bv.to_string() << endl;
}

void func2()
{
	std::vector<int> hit_bits{1, 2, 3, 5, 8, 13, 21};
	bitset<MAX_BIT_CNT> bv;

	for (auto bit : hit_bits)
	{
		bv.set(bit);
	}

	cout << bv.to_string() << endl;
}

int main()
{
	//func1();
	func2();

	return 0;
}
