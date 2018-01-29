// test: 测试stacktrace库

#include <iostream>

#include "libs/stacktrace.h"

using namespace std;

void a()
{
	print_stacktrace();
}

void b(int n)
{
	a();
}

void c()
{
	b(1);
}

int main()
{
	c();

	return 0;
}
