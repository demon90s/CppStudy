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
	Foo f1;
	Foo f2 = f1;
	Foo f3 = 10; // 可能不会调用拷贝构造函数，编译器直接优化成直接初始化：Foo f3(10)

	// 避免报warning
	f2.goo();
	f3.goo();

	return 0;
}
