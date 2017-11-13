// example: 字面值常量类（p267）
// 字面值常量类也是一种字面值类型，可以用于常量表达式

#include <iostream>

using namespace std;

class Debug
{
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { other = b; }

private:
	bool hw;	// 硬件错误
	bool io;	// IO错误
	bool other;	// 其他错误
};

int main()
{
	constexpr Debug io_sub(false, true, false);		// 调试IO
	if (io_sub.any()) {		// 等价于if(true)
		cerr << "print appropriate error message" << endl;
	}

	constexpr Debug prod(false);
	if (prod.any()) {		// 等价于if(false)
		cerr << "print an error message" << endl;
	}

	return 0;
}
