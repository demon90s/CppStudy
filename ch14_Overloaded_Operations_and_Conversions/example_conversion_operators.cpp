// example: 定义含有类型转换运算符的类（p514）

#include <iostream>
#include <stdexcept>

using namespace std;

class SmallInt
{
public:
	SmallInt(int i = 0) : val(i)
	{
		if (i < 0 || i > 255)
			throw std::out_of_range("Bad SamllInt value");
	}
	operator int() const { return val; }

	// 编译器不会自动执行这一类型的转换（拒绝隐式转换）
	explicit operator double() const { return val; }

	explicit operator bool() const { return val == 0; }

private:
	std::size_t val;
};

int main()
{
	SmallInt si;
	si = 4;		// 首先将4隐式地转换成SmallInt，然后调用SmallInt::operator=

	cout << si + 3 << endl; // 首先将si隐式地转换成int，然后执行整数的加法
	cout << static_cast<double>(si) + 3.14 << endl;

	si = 0;
	if (si)
	{
		cout << si << endl;
	}

	return 0;
}
