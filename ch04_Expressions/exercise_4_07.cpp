/*
 * 练习4.7：溢出是何含义？写出三条将导致溢出的表达式。
 */

/*
 * 当计算的结果超出该类型所能表示的范围时就会产生溢出。
 */

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	short sval = 32767;
	sval += 1;
	cout << sval << endl; // -32768

	char cval = 127;
	cval += 1;
	cout << (int)cval << endl; // -128

	unsigned uval = 0;
	uval -= 1;
	cout << uval << endl; // 4294967295

	return 0;
}
