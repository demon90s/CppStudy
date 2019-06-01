/*
 * 练习2.9：解释下列定义的含义。对于非法的定义，请说明错在何处并将其改正。
 *
 * (a) std::cin >> int input_value;		(b) int i = { 3.14 };
 * (c) double salary = wage = 9999.99;	(d) int i = 3.14;
 */

/*
 * (a) 格式错误。改正如下：
 *
 * int input_value = 0;
 * std::cin >> input_value;
 *
 * (b) 错误，列表初始化时，如果存在丢失信息的风险，编译器会报错。改为：double i = { 3.14 };
 *
 * (c) 格式错误。改为：double salary = 9999.99, wage = 9999.99; 或者先定义wage。
 *
 * (d) 正确。
 */

#include <iostream>

int main()
{
	//std::cin >> int input_value;
	int input_value = 0;
	std::cin >> input_value;

	//int i = { 3.14 };
	double i = { 3.14 };

	//double salary = wage = 9999.99;
	double salary = 9999.99, wage = 9999.99;

	int i2 = 3.14;

	return 0;
}
