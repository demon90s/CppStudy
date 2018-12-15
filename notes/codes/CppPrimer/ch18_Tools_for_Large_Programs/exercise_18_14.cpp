// 练习18.14：假设下面的operator*声明的是嵌套的命名空间mathLib::MatrixLib的一个成员，
// 请问你应该如何在全局作用域中声明该运算符？

#include <iostream>

namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &, const matrix &);
	}
}

// 声明
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix&, const matrix&);

int main()
{
	return 0;
}
