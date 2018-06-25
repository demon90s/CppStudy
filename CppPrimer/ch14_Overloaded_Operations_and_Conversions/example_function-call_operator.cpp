// example: 函数调用运算符（p506）

#include <iostream>

using namespace std;

struct AbsInt
{
	int operator()(int val) const {
		return val < 0 ? -val : val;
	}
};

int main()
{
	int i = -42;
	AbsInt abs_obj;
	cout << abs_obj(i) << endl;

	return 0;
}
