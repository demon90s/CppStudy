// example: 类模板（p583）

#include <string>
#include <iostream>
#include "Blob.h"

using namespace std;

void func1()
{
	Blob<int> ia;
	Blob<int> ia2 = {0, 1, 2, 3, 4};
}

void func2()
{
	Blob<string> str_blob = {"Hello", "World"};
	auto beg_ptr = str_blob.begin();

	*beg_ptr = "Hi";

	for (size_t i = 0; i < str_blob.size(); ++i)
		cout << str_blob[i] << " ";
	cout << endl;
}

// 实例化与成员模板
void func3()
{
	int ia[] = {0, 1, 2, 3};
	Blob<int> a1(begin(ia), end(ia));	
	for (size_t i = 0; i < a1.size(); ++i)
		cout << a1[i] << " ";
	cout << endl;
}

int main()
{
	//func2();
	func3();

	return 0;
}
