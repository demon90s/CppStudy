/*
 * 练习5.16：while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？
 */

/*
 * for的习惯用法，用while写。
 *
 * 我更倾向于使用for循环，因为其循环次数可控。用for循环也能完全模拟while循环。缺陷是for循环稍微会难阅读一点。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int sum = 0;
	int a = 0;
	while (a < 10) {
		sum += a;
		++a;
	}

	cout << sum << endl;

	return 0;
}
