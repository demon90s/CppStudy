/*
 * 练习6.25：编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char* argv[])
{
	int i = 0;
	string s;
	while (argv[i])
		s += argv[i++];

	cout << s << endl;
	return 0;
}
