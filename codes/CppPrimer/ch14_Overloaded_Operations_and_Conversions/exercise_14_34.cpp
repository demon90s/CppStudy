// 练习14.34：定义一个函数对象类，令其执行if-then-else的操作；该类的调用
// 运算符接受三个形参：它首先检查第一个形参，如果成功返回第二个形参的值；
// 如果不成功返回第三个形参的值。

#include <iostream>

using namespace std;

struct Foo
{
	int operator()(bool a, int b, int c) const
	{
		return a ? b : c;
	}
};

int main()
{
	Foo f1;
	cout << f1(true, 1, 10) << endl;
	cout << f1(false, 1, 10) << endl;

	return 0;
}
