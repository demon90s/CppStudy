/*
 * 练习6.54：编写函数声明，令其接受两个int形参并且返回类型也是int，然后
 * 声明一个vector对象，令其元素是指向该函数的指针。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

using pfunc = int (*)(int, int);

int main()
{
	vector<pfunc> pfunc_vec;

	return 0;
}
