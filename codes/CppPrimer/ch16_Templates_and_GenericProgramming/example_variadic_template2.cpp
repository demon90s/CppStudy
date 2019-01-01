// example: 编写可变参数函数模板（p620）

#include <iostream>
#include <string>
#include <sstream>

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

//-----------------------------------------------------------

// 打印任何我们不能处理的类型
template <typename T> string debug_rep(const T &t)
{
	ostringstream ret;
	ret << t;			// 使用T的输出运算符打印t的一个表示形式
	return ret.str();	// 返回ret绑定的string的一个副本
}

// 打印指针的值，后跟指针指向的对象
// 注意：此函数不能用于char*
template <typename T> string debug_rep(T *p)
{
	ostringstream ret;
	ret << "pointer: " << p; // 打印指针本身的值
	if (p)
		ret << " " << debug_rep(*p);	// 打印p指向的值
	else
		ret << " null pointer";			// 或指出p为空

	return ret.str();	// 返回ret绑定的string的一个副本
}

// 非模板
string debug_rep(const string &s)
{
	return '"' + s + '"';
}

// 将字符指针转换为string，并调用string版本的debug_rep
string debug_rep(char *p)
{
	return debug_rep(string(p));
}

string debug_rep(const char *p)
{
	return debug_rep(string(p));
}

// 在print调用中对每个实参调用debug_rep
template <typename... Args>
ostream &errorMsg(ostream &os, const Args&... rest)
{
	// print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an))
	return print(os, debug_rep(rest)...);
}

//-----------------------------------------------------------

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

// 理解包扩展（p622）
void func4()
{
	int a = 42;
	const char* str = "Hello";
	double pi = 3.14;

	errorMsg(cerr, a, &a, str, pi);
}

int main()
{
	//func1();
	//func2();
	func4();

	return 0;
}
