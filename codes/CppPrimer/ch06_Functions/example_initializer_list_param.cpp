// example: initializer_list形参（可变形参，p198）

#include <string>
#include <iostream>
#include <initializer_list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::initializer_list;

void error_msg(int error_num, initializer_list<string> il)
{
	cout << error_num << ": ";
	for (auto beg = il.begin(); beg != il.end(); ++beg)
		cout << *beg << " ";
	cout << endl;
}

int main()
{
	string actual = "hello";
	string expected;

	cin >> expected;

	if (expected != actual)
		error_msg(42, {__FUNCTION__, expected, actual});
	else
		error_msg(0, {__FUNCTION__, "okay"});

	return 0;
}
