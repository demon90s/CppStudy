// 练习9.48：假定name和numbers的定义如325页所示，numbers.find(name)返回
// 什么？

// string::npos

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string numbers = "0123456789";
	string name = "r2d2";

	if (string::npos == numbers.find(name))
		cout << "it's npos" << endl;

	return 0;
}
