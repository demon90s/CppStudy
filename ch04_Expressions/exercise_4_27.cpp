/*
 * 练习4.27：下列表达式的结果是什么？
 *
 * unsigned long ul1 = 3, ul2 = 7;
 * (a) ul1 & ul2	(b) ul1 | ul2
 * (c) ul1 && ul2	(d) ul1 | ul2
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	unsigned long ul1 = 3, ul2 = 7;

	cout << (ul1 & ul2) << endl;	// 0011 & 0111 --> 0011 --> 3
	cout << (ul1 | ul2) << endl;	// 0011 | 0111 --> 0111 --> 7
	cout << (ul1 && ul2) << endl;	// true --> 1
	cout << (ul1 || ul2) << endl;	// true --> 1

	return 0;
}
