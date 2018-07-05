// example: malloc函数与free函数与new, delete表达式

#include <iostream>
#include <cstdlib>
#include <new>

inline void *operator new(size_t size) {
	if (void *mem = malloc(size)) {
		std::cout << "[DEBUG] call custom new, ptr: " << mem << std::endl;
		return mem;
	}
	else
		throw std::bad_alloc();
}

inline void operator delete(void *mem) noexcept
{
	std::cout << "[DEBUG] call custom delete, ptr: " << mem << std::endl;
	free(mem);
}
