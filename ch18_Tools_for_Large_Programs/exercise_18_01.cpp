// 练习18.1：在下列throw语句中异常对象的类型是什么？如果将（b）中的throw语句写成了throw p将发生什么情况？

// 抛出的异常类型是表达式的静态类型。因此a是range_error，b是exception

// 抛出一个局部对象的指针，是错误的行为。见func_bad。

#include <iostream>
#include <stdexcept>

using namespace std;

void func_a()
{
	range_error r("error");
	throw r;
}

void func_b()
{
	range_error r("error");
	exception *p = &r;
	throw *p;
}

void func_bad()
{
	range_error r("error");
	exception *p = &r;
	throw p; 
}

int main()
{
	//func_a();
	//func_b();
	
	try {
		func_bad();
	} catch (exception *p)
	{
		cerr << p->what() << endl; // Segmentation fault (core dumped)
	}

	return 0;
}
