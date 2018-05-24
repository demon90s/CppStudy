// example: 编写可变参数函数模板（p620）

#include <iostream>
#include <string>

using namespace std;

// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的print定义之前声明
template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;	// 包中最后一个元素之后不打印分隔符
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";			// 打印第一个实参
	return print(os, rest...);	// 递归调用，打印其他实参
}

void func1()
{
	int i = 88;
	string s = "Hi";
	print(cout, i, s, 42);
}

// 练习16.53
void func2()
{
	int i = 88;
	string s = "Hi";
	char c1 = 'x';
	char c2 = 'd';
	double pi = 3.14;

	print(cout, i) << endl;
	print(cout, i, s) << endl;
	print(cout, i, s, c1, c2, pi) << endl;
}

// 练习16.54
void func3()
{
	struct NoOutOp
	{
	};

	NoOutOp obj;
	//print(cout, obj); // 编译报错
	

	(void)obj; // ignore warning
}

int main()
{
	//func1();
	func2();

	return 0;
}
