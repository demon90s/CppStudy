/*
 * 练习6.55：编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题
 * 创建的vector对象中保存指向这些函数的指针。
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

using pfunc = int (*)(int, int);

int Addition(int a, int b)
{
	return a + b;
}

int Subtraction(int a, int b)
{
	return a - b;
}

int Multiplication(int a, int b)
{
	return a * b;
}

int Division(int a, int b)
{
	return a / b;
}

int main()
{
	vector<pfunc> pfunc_vec;
	pfunc_vec.push_back(Addition);
	pfunc_vec.push_back(Subtraction);
	pfunc_vec.push_back(Multiplication);
	pfunc_vec.push_back(Division);

	return 0;
}
