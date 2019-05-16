/*
 * s.append(args) 将 args 追加到s，返回一个指向s的引用。
 */

#include <iostream>
#include <string>

int main()
{
	std::string s = "C++ Primer";

	s.append(" 4th Ed.");

	std::cout << s << std::endl;

	return 0;
}
