/*
 * 练习6.37：为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype
 * 关键字。你觉得哪种形式最好？为什么？
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

/* Type (*function(parameter_list))[dimension]; */
string (&func())[10];

// 使用类型别名
using StrArr = string[10];
StrArr &func();

// 使用尾置返回类型
auto func() -> string(&)[10];

// 使用decltype
string str_arr[10];
decltype(str_arr) &func();

// 使用类型别名好点，因为看上去更清晰易懂。

int main()
{
	return 0;
}
