// example: malloc函数与free函数与new, delete表达式
// 当使用 new 操作的时候, 会调用一个 operator new 的函数, 它用来给对象分配内存, 然后在这块内存上构造对象
// 如果申请不了内存, operator new 就要抛出一个 bad_alloc 的异常

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