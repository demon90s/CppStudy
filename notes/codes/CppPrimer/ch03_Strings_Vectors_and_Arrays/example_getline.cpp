// example: 使用getline读取一整行（p78）
// ./example_getline < example_getline.cpp

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string line;
	// 每次读取一整行，直至到达文件尾
	while (getline(cin, line))
		cout << line << endl;

	return 0;
}
