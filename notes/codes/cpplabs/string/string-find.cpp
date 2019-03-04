/*
 * s.find(args) 查找s中 args 第一次出现的位置
 * s.find(args, pos) 查找s中始于 pos 位置的 args 第一次出现的位置
 * 
 * 找不到返回 npos
 */

#include <iostream>
#include <string>

void test1()
{
	std::string name = "AnnaBelle";

	auto pos = name.find("Bell");
	if (pos == std::string::npos) {
		std::cout << "not find" << std::endl;
	}
	else {
		std::cout << "find pos: " << pos << std::endl;
	}
}

// test s.find(args, pos)
void test2()
{
	std::string str = "a:b:c:";

	std::string::size_type pos_beg = 0;
	auto pos = str.find(":", pos_beg);
	while (pos != std::string::npos)
	{
		std::cout << std::string(str, pos_beg, pos - pos_beg) << std::endl;

		pos_beg = pos + 1;
		pos = str.find(":", pos_beg);
	}

	if (pos_beg != str.length())
	{
		std::cout << std::string(str, pos_beg) << std::endl;
	}
}

int main()
{
	//test1();
	test2();

	return 0;
}
