/*
 * 测试位运算
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	signed char c = 1;
	cout << (c << 31) << endl;	// 负数，signed char被提升为int

	unsigned char uc = 1;
	cout << (uc << 31) << endl;	// 负数，unsigned char也被提升为int

	unsigned int ui = 1;
	cout << (ui << 31) << endl;	// 正数

	return 0;
}
