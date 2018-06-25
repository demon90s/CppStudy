// 练习12.23：编写一个程序，连接两个字符串字面量，将结果保存在一个动态分配的
// char数组中。重写这个程序，连接两个标准库string对象。

#include <cstring>

#include <iostream>
#include <memory>
#include <string>

using namespace std;

void func1()
{
	const char *str1 = "hello";
	const char *str2 = " world";

	unique_ptr<char[]> up(new char[strlen(str1) + strlen(str2)]());
	
	for (size_t i = 0; i < strlen(str1); ++i)
	{
		up[i] = str1[i];
	}

	size_t offset = strlen(str1);
	for (size_t i = 0; i < strlen(str2); ++i)
	{
		up[i + offset] = str2[i];
	}


	// print
	for (size_t i = 0; i < strlen(str1) + strlen(str2); ++i)
	{
		cout << up[i];
	}
	cout << endl;
}

void func2()
{
	string str1 = "hello";
	string str2 = " world";

	unique_ptr<char[]> up(new char[str1.length() + str2.length()]());
	
	for (size_t i = 0; i < str1.length(); ++i)
	{
		up[i] = str1[i];
	}

	size_t offset = str1.length();
	for (size_t i = 0; i < str2.length(); ++i)
	{
		up[i + offset] = str2[i];
	}


	// print
	for (size_t i = 0; i < str1.length() + str2.length(); ++i)
	{
		cout << up[i];
	}
	cout << endl;
	
}

int main()
{
	//func1();
	func2();

	return 0;
}
