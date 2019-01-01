// 练习14.51：在调用calc的过程中，可能用到哪些类型转换序列呢？说明最佳可行函数
// 是如何被选出来的。

#include <iostream>

using namespace std;

struct LongDouble {
	LongDouble(double _v = 0.0) : v(_v) {}
	operator double() { cout << "operator double" << endl; return v; }
	operator float() { cout << "operator float" << endl; return (float)v; }

	double v;
};

void calc(int) { cout << "calc(int)" << endl; }
void calc(LongDouble) { cout << "calc(LongDouble)" << endl; }

int main()
{
	double dval = 0;
	calc(dval);		// 哪个calc？ -> calc(int)

	// class-type conversion is the lowest ranked

	return 0;
}
