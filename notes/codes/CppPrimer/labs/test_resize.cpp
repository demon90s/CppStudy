// test: 测试resize

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "Hello";
	a.resize(0);

	cout << a << endl;
	cout << a.length() << endl;

	return 0;
}
