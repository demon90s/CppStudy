/*
 * 练习2.10：下列变量的初值分别是什么？
 *
 * std::string global_str;
 * int global_int;
 * int main()
 * {
 *     int local_int;
 *     std::string local_str;
 * }
 */

/*
 * global_str是一个空串，global_int是0，local_int的值未定义，local_str是一个空串。
 */

#include <iostream>
#include <string>

std::string global_str;
int global_int;
int main()
{
	int local_int;
	std::string local_str;

	std::cout << "global_str: " << global_str << std::endl;
	std::cout << "global_int: " << global_int << std::endl;
	std::cout << "local_int: " << local_int << std::endl;
	std::cout << "local_str: " << local_str << std::endl;

	return 0;
}
