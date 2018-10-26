// example: allocator类（427）

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Bar
{
public:
	Bar() { cout << "Bar()" << endl; }
	Bar(const Bar&) { cout << "Bar(const Bar&)" << endl; }
	~Bar() { cout << "~Bar()" << endl; }
};

int main()
{
	static constexpr size_t N = 3;

	vector<Bar> vec;
	vec.resize(N); // 调用构造函数

	allocator<Bar> alloc;

	// allocate: 分配适当字节对齐并有Bar类型的N个对象的内存块，返回内存块首地址
	auto const p = alloc.allocate(N);

	// uninitialized_copy: 复制来自[first, last)的元素到始于p的未初始化内存
	auto const q = uninitialized_copy(vec.begin(), vec.end(), p); // 调用拷贝构造函数

	// destroy: 销毁对象，即对对象执行析构函数
	{
		auto beg = p, end = q;
		while (beg != end)
			alloc.destroy(--end); // 调用析构函数
	}

	// deallocate: 释放从p开始的内存
	alloc.deallocate(p, N);

	return 0;
}
