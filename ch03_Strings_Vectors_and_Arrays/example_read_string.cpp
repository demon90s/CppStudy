// example: 读取未知数量的string对象（p78）

/*
 * ./example_read_string < example_read_string.cpp
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string word;
	while (cin >> word)
		cout << word << endl;

	return 0;
}
