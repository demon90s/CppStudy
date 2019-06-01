#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// 用于表示银行的账户记录
class Account
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();

	static constexpr double baseRate = 1.0;
};

#endif
