/*
 * s.find(args) 查找s中 args 第一次出现的位置
 */

#include <iostream>
#include <string>

int main()
{
	std::string name = "AnnaBelle";

	auto pos = name.find("Bell");
	if (pos == std::string::npos) {
		std::cout << "not find" << std::endl;
	}
	else {
		std::cout << "find pos: " << pos << std::endl;
	}

	return 0;
}
