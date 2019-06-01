/*
 * 练习8.1：编写函数，接受一个istream&参数，返回值类型也是istream&。此函数须从给定流中读取数据，
 * 直至遇到文件结束符标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，
 * 对流进行复位，使其处于有效状态。
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::istream& print(std::istream &is)
{
	string word;
	while (is >> word)
		cout << word << endl;

	is.clear();
	return is;
}

int main()
{
	print(cin);
	return 0;
}
