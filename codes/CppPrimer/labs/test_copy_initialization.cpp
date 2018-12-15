// test：测试拷贝初始化

#include <iostream>

using namespace std;

class Foo
{
public:
	Foo() : a(0) {}
	Foo(const Foo &f) : a(f.a) { cout << "copy construct called，a: " << a << endl; }
	Foo(int _a) : a(_a) {}

	void goo() { cout << a << endl; }
private:
	int a;
};

int main()
{
	{
		Foo f(1);
		Foo f1 = f;
		(void)f1;
	}

	Foo f2 = 2; // 可能不会调用拷贝构造函数，编译器直接优化成直接初始化：Foo f3(10)
	(void)f2;

	return 0;
}
