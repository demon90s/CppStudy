// example: 重载与模板(p615)

#include <iostream>
#include <sstream>

using namespace std;

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

void func1()
{
	int i = 42;
	cout << debug_rep(i) << endl;
}

void func2()
{
	int i = 42;
	cout << debug_rep(&i) << endl;
}

void func3()
{
	string s = "hi";
	cout << debug_rep(s) << endl;
}

void func4()
{
	cout << debug_rep("Wow") << endl;
}

int main()
{
	//func1();
	//func2();
	//func3();
	func4();

	return 0;
}
