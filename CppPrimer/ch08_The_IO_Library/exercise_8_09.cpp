/*
 * 练习8.9：使用你为8.1.2节（第281页）第一个练习所编写的函数打印一个
 * istringstream对象的内容。
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
	string s = "hello world";
	istringstream iss(s);

	print(iss);
	return 0;
}
