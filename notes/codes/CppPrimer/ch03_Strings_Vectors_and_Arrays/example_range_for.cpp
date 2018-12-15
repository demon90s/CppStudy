// example: 使用基于范围for语句处理每个字符（p82）

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
	string str("some string");
	// 每行输出str中的一个字符
	for (auto c : str)
		cout << c << endl;

	return 0;
}
