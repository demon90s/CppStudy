/*
 * 练习5.16：while循环特别适用于那种条件保持不变、反复执行操作的情况，例如，当未达到文件末尾时不断读取下一个值。for循环则更像是在按步骤迭代，它的索引值在某个范围内依次变化。根据每种循环的习惯用法各自编写一段程序，然后分别用另一种循环改写。如果只能使用一种循环，你倾向于使用哪种呢？为什么？
 */

/*
 * while的习惯用法，使用for写。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int a = 0;
	for (; cin >> a;)
		cout << a << endl;

	return 0;
}
