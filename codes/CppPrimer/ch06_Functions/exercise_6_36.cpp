/*
 * 练习6.36：编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不要使用尾置返回类型、
 * decltype或者类型别名。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

/* Type (*function(parameter_list))[dimension]; */
string (&func())[10];

int main()
{
	return 0;
}
