/*
 * 调用fact函数
 */

#include <iostream>
#include "../Chapter6.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n = 5;
	cout << n << "! is " << fact(n) << endl;

	return 0;
}
