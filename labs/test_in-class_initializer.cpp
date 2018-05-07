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

class Boo
{
public:
	Boo() : b(100) {}

	int a = 10;
	int b;
};

struct Foo
{
	int a = 10;				// 初始化普通内置类型
	int array[10] = {0};	// 初始化内置数组
	string s = "hello";
	Goo g{10};				// 列表初始化有显式构造函数的类
	Moo m{1, 2};			// 列表初始化聚合类

	int b;					// 默认初始化，内置类型其值由定义位置决定
	Boo boo;				// 默认初始化类类型，数据成员用默认构造函数的初始化列表初始化，如果没有，则用类内初始值初始化，如果没有，则默认初始化
};

int main()
{
	Foo foo;
	cout << "a: " << foo.a << endl;
	cout << "s: " << foo.s << endl;
	cout << "b: " << foo.b << endl;
	cout << "boo.a: " << foo.boo.a << endl;
	cout << "boo.b: " << foo.boo.b << endl;

	return 0;
}
