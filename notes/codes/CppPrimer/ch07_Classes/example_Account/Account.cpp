#include "Account.h"

double Account::initRate()
{
	return 2.0;
}

// 即使一个常量静态数据成员在类内部被初始化了，通常情况下也应该在类的外部定义一下该成员（p271）
constexpr double Account::baseRate;

// 定义并初始化一个静态成员
double Account::interestRate = initRate();

void Account::rate(double newRate)
{
	interestRate = newRate;
}
