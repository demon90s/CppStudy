// 练习18.20：在下面的代码中，确定哪个函数与compute调用匹配。列出所有候选函数
// 和可行函数，对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？

// 如果将using声明置于main函数中compute的调用点之前将发生什么情况？重新回答之前
// 的那些问题。

// answer：这里面定义的所有compute都是候选函数，除了compute()，其他都是可行函数，
// 都是把int类型转换成对应的形参类型，只有compute(int)最为匹配。
// 如果把using声明放到main中compute的调用点之前，那么候选函数中就没有primerLib中
// 的compute函数，候选函数则全部是可行函数，但最匹配的还是compute(int)。

#include <iostream>

namespace primerLib {
	void compute();
	void compute(const void *);
}

//using primerLib::compute;
void compute(int) { std::cout << "compute(int)" << std::endl; } // 最为匹配的函数
void compute(double, double = 3.4);
void compute(char*, char* = 0);

void f()
{
	compute(0);
}

int main()
{
	using primerLib::compute;
	f();

	return 0;
}
