// example: 自定义的make_shared，练习16.61

#include <iostream>
#include "MakeShared.h"

class Foo
{
public:
	Foo() { std::cout << "Foo()" << std::endl; }
	Foo(int, int) { std::cout << "Foo(int, int)" << std::endl; }
	~Foo() { std::cout << "~Foo()" << std::endl; }
};

int main()
{
	//auto p = MakeShared<Foo>();
	auto p2 = MakeShared<Foo>(1, 2);

	return 0;
}
