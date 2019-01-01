/*
 * 练习6.26：编写一个程序，使其接受本节所示的选项：输出传递给main函数的实参的内容。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i)
		cout << argv[i] << endl;

	return 0;
}
