/*
 * 练习6.3：编写你自己的fact函数，上机检查是否正确。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int fact(int n)
{
	int ret = 1;
	for (; n > 1; --n) {
		ret *= n;
	}
	return ret;
}

int main()
{
	cout << fact(5) << endl;

	return 0;
}
