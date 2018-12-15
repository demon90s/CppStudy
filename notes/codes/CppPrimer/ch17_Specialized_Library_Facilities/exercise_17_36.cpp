// 练习17.36：修改上一题中的程序，打印不同的浮点数，使它们排成一列。

// 练习17.35：修改第670页中的程序，打印2的平方根，但这次打印十六进制数字的大写形式。

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void func(float v)
{
	// PS: 使用我当前的编译器(4.8.5)无法正确编译，采用devtoolset-4的编译器又无法正常运行
	// 采用最简单的方法，直接去在线编译：http://coliru.stacked-crooked.com/
	cout << hexfloat << uppercase << v << endl;
}

int main()
{
	func(3.14);
	func(sqrt(2));

	return 0;
}
