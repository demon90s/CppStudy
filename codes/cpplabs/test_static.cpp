// test: static的3个用途

#include <iostream>

#define USE_VAR(x) ((void)&(x))

using namespace std;

class Bar
{
public:
	Bar() { std::cout << "Bar()\n"; }
	~Bar() { std::cout << "~Bar()\n"; }
};
static Bar bar;			// 1. 内部链接，全局静态变量，在 main 函数前初始化(执行构造函数), 在 main 函数结束后析构

static int a = 0;		// 1. 内部链接的变量

static void f() {		// 1. 内部链接的函数
} 

int g() {
	static int b = 0;	// 2. 静态局部变量
	b++;
	return b;
}

class Foo {
	static void h();	// 3. 静态成员函数声明
	static int c;		// 3. 静态成员变量声明

	// 特殊：可以为静态成员提供const整数类型的类内初始值，且要求静态成员必须是字面值常量类型。
	static const int d = 10;
};

void Foo::h() {			// 3. 静态成员函数定义
}

int Foo::c = 0;			// 3. 静态成员变量定义

int main()
{
	std::cout << "main begin\n";

	USE_VAR(a);
	USE_VAR(f);

	std::cout << "main end\n";
	return 0;
}
