/*
 * 练习7.27：给你自己的Screen类添加move、set和display函数，通过执行下面
 * 的代码检查你的类是否正确。
 */

#include <iostream>
#include "example_Screen/Screen.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	return 0;
}
