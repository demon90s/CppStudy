/*
 * s.erase(pos, len) 删除从位置 pos 开始的 len 个字符。如果 len 被省略，则删除
 * 从 pos 开始至s末尾的所有字符。返回一个指向s的引用。
 */

#include <iostream>
#include <string>

int main()
{
	std::string s = "Hello World";

	s.erase(5);

	std::cout << s << std::endl;

	return 0;
}
