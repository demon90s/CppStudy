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

int main()
{
	func2();

	return 0;
}
