#include <string>
#include <iostream>

int main()
{
	// s.substr(pos, n)
	
	// 返回一个 string ，包含s中从 pos 开始的 n 个字符的拷贝。 pos 的默认值为0。
	// n 的默认值为 s.size() - pos ，即拷贝从 pos 开始的所有字符。
	//
	// 如果开始位置超过了 string 的大小（pos > s.size()），则抛出 out_of_range 异常。
	//
	std::string s("Hello world");
	std::string s2 = s.substr(0, 5); 	// hello
	std::string s3 = s.substr(6);		// world
	std::string s4 = s.substr(6, 3);	// wor

	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;

	return 0;
}
