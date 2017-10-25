// example: 使用引用传递避免拷贝（p189）

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

// compare the length of two strings
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	string str1 = "Hi";
	string str2 = "Hello";
	if (isShorter(str1, str2))
		cout << str1 << " is shorter than " << str2 << endl;

	return 0;
}
