/*
 * 练习1.15：编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。
 */

#include <iostream>

int main()
{
	// 语法错误（syntax error）
	//std::cout << "Hello" << std::endl:

	// 类型错误（type error）
	//int a = "Hello";

	// 声明错误（declaration error）
	cout << "Hello" << std::endl;

	return 0;
}
