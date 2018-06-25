// example: 窗口类的设计与实现(自p243始)

#include <iostream>
#include "Window_mgr.h"

using std::cout;
using std::endl;

int main()
{
	Screen screen(5, 3, 'A');

	screen.set('#').display(cout);

	cout << endl;

	return 0;
}
