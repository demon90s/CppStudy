// 练习14.53：假设我们已经定义了如522页所示的SmallInt，判断下面的加法表达式是否合法。
// 如果合法，使用了哪个加法运算符？如果不合法，应该怎样修改代码才能使其合法。

#include <iostream>

using namespace std;

class SmallInt {
	friend SmallInt operator+(const SmallInt&, const SmallInt&);

public:
	SmallInt(int _v = 0) : val(_v) {}
	operator int() const { return val; }

private:
	std::size_t val;
};

SmallInt operator+(const SmallInt &lhs, const SmallInt &rhs)
{
	cout << "operator+(const SmallInt &lhs, const SmallInt &rhs)" << endl;

	SmallInt ret;
	ret.val = lhs.val + rhs.val;
	return ret;
}

int main()
{
	SmallInt s1;
	//double d = s1 + 3.14; // error: ambiguous overload for ‘operator+’
	
	double d = static_cast<int>(s1) + 3.14;

	cout << d << endl;

	return 0;
}
