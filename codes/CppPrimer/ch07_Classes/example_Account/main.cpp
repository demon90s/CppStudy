// example: 类的静态成员（p269）

#include "Account.h"
#include <iostream>

using namespace std;

int main()
{
	double r = Account::rate();	// 使用作用域运算符访问静态成员
	cout << "rate: " << r << endl;

	return 0;
}
