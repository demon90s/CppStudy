/*
 * 练习2.14：下面的程序合法吗？如果合法，它将输出什么？
 *
 * int i = 100, sum = 0;
 * for (int i = 0; i != 10; ++i)
 *     sum += i;
 * std::cout << i << " " << sum << std::endl;
 */

/*
 * 合法，将输出：100 45（换行）
 */

#include <iostream>

int main()
{
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
		sum += i;
	std::cout << i << " " << sum << std::endl;

	return 0;
}
