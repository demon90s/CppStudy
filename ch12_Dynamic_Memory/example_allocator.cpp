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
	auto const p = alloc.allocate(N);

	auto const q = uninitialized_copy(vec.begin(), vec.end(), p); // 调用拷贝构造函数

	// destroy
	{
		auto beg = p, end = q;
		while (beg != end)
			alloc.destroy(--end); // 调用析构函数
	}

	alloc.deallocate(p, N);

	return 0;
}
