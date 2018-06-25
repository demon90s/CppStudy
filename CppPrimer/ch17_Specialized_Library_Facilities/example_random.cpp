// example: 随机数（p659）

// PS: 出于演示的目的，实用性有待确认。

#include <iostream>
#include <random>
#include <vector>

using namespace std;

// 通过随机数引擎对象生成原始随机数
void func1()
{
	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
	{
		cout << e() << " ";
	}
	cout << endl;
}

// 生成0到9之间（包含）均匀分布的随机数
void func2()
{
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;
	for (size_t i = 0; i < 10; ++i)
	{
		// 将u作为随机数源
		// 每个调用返回指定范围内并服从均匀分布的值
		cout << u(e) << " ";
	}
}

// 正确的方法：将引擎和关联的分布对象定义为static的
// 返回一个vector，包含100个均匀分布的随机数
vector<unsigned> good_randVec()
{
	// 由于我们希望引擎和分布对象保持状态，因此应该将它们
	// 定义为static的，从而每次调用都生成新的数
	static default_random_engine e;
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 100; ++i)
	{
		ret.push_back(u(e));
	}

	return ret;
}

// 设置随机数种子
void func3()
{
	static uniform_int_distribution<unsigned> u(0, 9);
	static default_random_engine e(time(0));

	for (size_t i = 0; i != 10; ++i)
	{
		cout << u(e) << " ";
	}
	cout << endl;
}

// 正态分布的随机数
void func4()
{
	default_random_engine e;
	normal_distribution<> n(4, 1.5);

	vector<unsigned> vals(9);

	for (size_t i = 0; i != 200; ++i) {
		unsigned v = lround(n(e));	// 舍入到最接近的整数
		if (v < vals.size())		// 如果结果在范围内
			++vals[v];				// 统计每个数出现了多少次
	}

	for (size_t j = 0; j != vals.size(); ++j)
		cout << j << ": " << string(vals[j], '*') << endl;
}

int main()
{
	//func1();
	//func2();
	
	/*
	if (good_randVec() != good_randVec())
	{
		cout << "different random result" << endl;
	}
	*/

	/*
	for (int i = 0; i < 3; ++i)
	{
		func3();
	}
	*/

	func4();

	return 0;
}
