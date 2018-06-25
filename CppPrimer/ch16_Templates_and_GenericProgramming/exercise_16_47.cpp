// 练习16.47：编写你自己版本的翻转函数，通过调用接受左值和右值引用参数的函数
// 来测试它。

#include <iostream>

using namespace std;

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
	f(t2, t1);
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void g1(int &&i, int &j)
{
	j = i;
}

int main()
{
	int a = 0;
	//flip2(g1, a, 42); // cannot bind ‘int’ lvalue to ‘int&&’
	flip(g1, a, 42);
	cout << a << endl;

	return 0;
}
