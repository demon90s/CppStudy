// 练习19.1：使用malloc编写你自己的operator new(size_t)函数，使用free编写
// operator delete(void*)函数。

#include <cstdlib>
#include <new>
#include <iostream>

using namespace std;

void *operator new(size_t sz) {
	if (void *mem = malloc(sz))
		return mem;
	else
		throw bad_alloc();
}

void operator delete(void *mem) noexcept
{
	free(mem);
}

int main()
{
	int *ip = new int;
	cout << ip << endl;
	delete ip;
	ip = 0;

	return 0;
}
