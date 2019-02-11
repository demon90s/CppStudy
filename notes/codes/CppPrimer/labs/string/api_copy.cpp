/*
std::string::copy

size_type copy(char *dest, size_type count, size_type pos = 0) const;

复制子串 [pos, pos + count) 到 dest 所指的字符串。

若请求的子串越过 string 结尾，或若 count == npos ，则复制的子串为 [pos, size()) ，产生的字符串结尾没有空字符。

若 pos > size() ，则抛出 std::out_of_range 。

返回复制的字符数。
*/

#include <iostream>
#include <string>

void test1()
{
	std::string str = "Hello World";

	char *cstr = new char[str.length() + 1]{};

	str.copy(cstr, std::string::npos);

	std::cout << "cstr: " << cstr << std::endl;

	delete []cstr;
}

int main()
{
	test1();
	return 0;
}
