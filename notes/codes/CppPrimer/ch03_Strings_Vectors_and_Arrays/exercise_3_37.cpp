/*
 * 练习3.37：下面的程序是何含义，程序的输出结果是什么？
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	//--------------------------------------------
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}
	//--------------------------------------------
	
	// 上面这段程序是想输出ca数组的内容，然而此数组未以空字符结尾，运行的结果未定义

	return 0;
}
