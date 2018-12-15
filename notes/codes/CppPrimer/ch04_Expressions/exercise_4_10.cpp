/*
 * 练习4.10：为while循环写一个条件，使其从标准输入中读取整数，遇到42时停止。
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int iv;
	while (cin >> iv && iv != 42);

	return 0;
}
