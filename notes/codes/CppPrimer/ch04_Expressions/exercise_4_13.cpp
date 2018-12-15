/*
 * 练习4.13：在下述语句中，当赋值完成后i和d的值分别是多少？
 *
 * int i; double d;
 * (a) d = i = 3.5;
 * (b) i = d = 3.5;
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int i; double d;

	d = i = 3.5;
	cout << d << " " << i << endl;	// 3 3

	i = d = 3.5;
	cout << d << " " << i << endl;  // 3.5 3

	return 0;
}
