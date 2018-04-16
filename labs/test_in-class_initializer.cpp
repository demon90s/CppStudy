// test: 测试类内初始值

#include <iostream>
#include <string>

using namespace std;

class Goo
{
public:
	explicit Goo(int _n) : n(_n) {}

private:
	int n;
};

struct Moo
{
	int n;
	int m;
};

struct Foo
{
	int a = 10;				// 初始化普通内置类型
	int array[10] = {0};	// 初始化内置数组
	string s = "hello";
	Goo g{10};				// 列表初始化有显式构造函数的类
	Moo m{1, 2};			// 列表初始化聚合类

	int b;					// 默认初始化，内置类型其值未定义
};

int main()
{
	Foo foo;
	cout << "a: " << foo.a << endl;
	cout << "s: " << foo.s << endl;
	cout << "b: " << foo.b << endl;

	return 0;
}
