// 练习16.26：假设NoDefault是一个没有默认构造函数的类，我们可以显式实例化
// vector<NoDefault>吗？如果不可以，解释为什么？

#include <iostream>
#include <vector>

using namespace std;

class NoDefault
{
public:
	explicit NoDefault(int a) : m_a(a) {}

private:
	int m_a = 0;
};

//template class vector<NoDefault>; // ERROR: 显式实例化会定义实例化所有成员

int main()
{
	vector<NoDefault> vec; // OK, 因为没有使用到默认构造函数，无须实例化这个成员

	return 0;
}
