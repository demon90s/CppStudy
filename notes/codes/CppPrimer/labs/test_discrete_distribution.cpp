// 测试随机抽样分布，参考：http://zh.cppreference.com/w/cpp/numeric/random/discrete_distribution

#include <iostream>
#include <map>
#include <random>
#include <initializer_list>

using namespace std;

void example_func()
{
	random_device rd;
	mt19937 gen(rd());
	discrete_distribution<> d({40, 10, 10, 40});
	map<int, int> m;

	for (int n = 0; n < 10000; ++n) {
		++m[d(gen)];
	}

	for (auto p : m)
	{
		cout << p.first << "generated " << p.second << " times\n";
	}
}

class DiscreteRandom
{
public:
	DiscreteRandom() : m_gen(m_rd()) {}
	unsigned int Gen(const initializer_list<double> &il);

private:
	random_device m_rd;
	mt19937 m_gen;
};

unsigned int DiscreteRandom::Gen(const initializer_list<double> &il)
{
	discrete_distribution<> d(il);
	return d(m_gen);
}

void func()
{
	DiscreteRandom r;

	map<int, int> m;

	for (int n = 0; n < 10000; ++n) {
		++m[r.Gen({40, 10, 10, 40})];
	}

	for (auto p : m)
	{
		cout << p.first << " generated " << p.second << " times\n";
	}
}

int main()
{
	//example_func();
	
	func();

	return 0;
}
