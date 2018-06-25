// example: 使用下标执行迭代（p85）
// 使用下标进行迭代

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string s("Hello World");

	// 依次处理s中的字符直至我们处理完全部字符或遇到一个空白
	for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
		s[index] = toupper(s[index]);

	cout << s << endl;

	return 0;
}
