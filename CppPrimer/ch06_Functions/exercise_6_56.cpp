/*
 * 练习6.56：调用上述vector中的每个元素并输出其结果。
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

	int a = 10, b = 5;
	for (auto f : pfunc_vec) {
		cout << f(a, b) << endl;
	}

	return 0;
}
