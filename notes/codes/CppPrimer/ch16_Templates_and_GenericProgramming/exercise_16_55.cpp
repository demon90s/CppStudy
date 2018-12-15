// 练习16.55：如果我们的可变参数版本print的定义之后声明非可变阐述版本，解释
// 可变参数的版本会如何执行。

// error: no matching function for call to ‘print(std::ostream&)’

#include <iostream>
#include <string>

using namespace std;

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
	os << t << ", ";			// 打印第一个实参
	return print(os, rest...);	// 递归调用，打印其他实参
}

// 用来终止递归并打印最后一个元素的函数
// 此函数必须在可变参数版本的print定义之前声明
template <typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;	// 包中最后一个元素之后不打印分隔符
}

void func1()
{
	int i = 88;
	string s = "Hi";
	print(cout, i, s, 42);
}

int main()
{
	func1(); 

	return 0;
}
