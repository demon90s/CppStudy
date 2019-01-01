/*
 * s.rfind(args) 查找s中 args 最后一次出现的位置
 */

#include <iostream>
#include <string>

int main()
{
	std::string s = "AnnieBellenie";

	auto pos = s.rfind("nie");
	std::cout << pos << std::endl;

	return 0;
}
