// 练习12.24：编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组
// 中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度
// 的字符串。

#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t length = 0; // 分配的动态数组的长度
	string word;

	cout << "Enter length: ";
	cin >> length;

	cout << "Enter word: ";
	cin >> word;

	if (length < word.length() + 1)
	{
		cout << "length not enough!";
		return 1;
	}

	char *str = new char[length]();
	for (size_t i = 0; i < length; ++i)
	{
		str[i] = word[i];
	}

	// print
	cout << str << endl;

	delete []str;

	return 0;
}
