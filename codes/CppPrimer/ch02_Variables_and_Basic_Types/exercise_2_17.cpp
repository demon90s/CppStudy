/*
 * 练习2.17：执行下面的代码段将输出什么结果？
 *
 * int i, &ri = i;
 * i = 5; ri = 10;
 * std::cout << i << " " << ri << std::endl;
 */

/*
 * 10 10(换行)
 */

#include <iostream>

int main()
{
	int i, &ri = i;
	i = 5; ri = 10;
	std::cout << i << " " << ri << std::endl;

	return 0;
}
