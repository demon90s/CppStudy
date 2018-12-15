/*
 * 练习7.38：有些情况我们希望提供cin作为接受istream&参数的构造函数的默认
 * 实参，请声明这样的构造函数。
 */

/*
 * 如下Foo类。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Foo
{
public:
	Foo(std::istream &is = std::cin) { is >> a; }

	void print() { std::cout << a << std::endl; }

private:
	int a = 0;
};

int main()
{
	Foo foo;
	foo.print();

	return 0;
}
