// example: 定位new表达式（p729）

#include <iostream>

struct Foo
{
	Foo(int _a, int _b) : a(_a), b(_b) {}
	int a, b;
};

int main()
{
	char *buffer = new char[sizeof(Foo)];

	auto foo = new (buffer) Foo(2, 3); // 定位new不分配内存，只在预先分配的内存地址上构造对象
	std::cout << foo->a << " " << foo->b << std::endl;

	std::cout << "foo address: " << foo << std::endl;
	std::cout << "buffer address: " << (void*)buffer << std::endl;

	delete []buffer;

	return 0;
}
