// 练习19.26：说明下列声明语句的含义并判断它们是否合法。

// 声明这个函数的定义是用C语言编写的。
// 不合法，因为C语言不支持函数重载，而这两个函数是一组重载函数。

extern "C" int compute(int*, int);
//extern "C" double compute(double*, double);

int main()
{
	return 0;
}
