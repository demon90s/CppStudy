// 练习16.49：解释下面每个调用会发生什么。

#include <iostream>

using namespace std;

template <typename T> void f(T) { cout << "f(T)" << endl; }

template <typename T> void f(const T*) { cout << "f(const T*)" << endl; }

template <typename T> void g(T) { cout << "g(T)" << endl; }

template <typename T> void g(T*) { cout << "g(T*)" << endl; }

int main()
{
	int i = 42, *p = &i;
	const int ci = 0, *p2 = &ci;

	g(42);		// g(T)
	g(p);		// g(T*)
	g(ci);		// g(T)
	g(p2);		// g(T*)

	f(42);		// f(T)
	f(p);		// f(T)
	f(ci);		// f(T)
	f(p2);		// f(const T*)

	return 0;
}
