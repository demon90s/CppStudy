// example: malloc函数与free函数与new, delete表达式
// 如果是类类型，那么先到类中的作用域查找 operator new 和 operator delete 操作符，然后到外层作用域中查找

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

inline void *operator new[](size_t sz) {
	if (void *mem = malloc(sz)) {
		std::cout << "[DEBUG] call custom new[], sz: " << sz << " ptr: " << mem << std::endl;
		return mem;
	}
	else
		throw std::bad_alloc();
}

inline void operator delete[](void *mem) noexcept
{
	std::cout << "[DEBUG] call custom delete[], ptr: " << mem << std::endl;
	free(mem);
}

class Foo {
public:
	Foo() { std::cout << "Foo::Foo()\n"; }
	~Foo() { std::cout << "Foo::~Foo\n"; }

	void *operator new(size_t sz) {
		if (void *mem = malloc(sz)) {
			std::cout << "[DEBUG] alloc an object of Foo\n";
			return mem;
		}
		else
			throw std::bad_alloc();
	}

	void operator delete(void *mem) noexcept {
		std::cout << "[DEBUG] free an object of Foo\n";
		free(mem);
	}
};