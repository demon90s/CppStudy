// 练习13.58：编写新版本的Foo类，其sorted函数中有打印语句，测试这个类，来
// 验证你对前两题的答案是否正确。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Foo {
public:
	Foo &operator=(const Foo&) &; 	// 只能向可修改的左值赋值

	Foo someMem() const &;			// 正确，const限定符在前

	Foo sorted() &&;				// 可用于可改变的右值
	Foo sorted() const &;			// 可用于任何类型的Foo

private:
	int a = 0;
	vector<int> data;
};

Foo &Foo::operator=(const Foo &rhs) &
{
	a = rhs.a;
	return *this;
}

// 本对象为右值，因此可以原址排序
Foo Foo::sorted() &&
{
	cout << "Foo Foo::sorted() &&" << endl;

	sort(data.begin(), data.end());
	return *this;
}

// 练习13.56，导致无限递归的版本
/*
Foo Foo::sorted() const &
{
	cout << "Foo Foo::sorted() const &" << endl;

	Foo ret(*this);
	return ret.sorted();
}
*/

// 练习13.57，调用右值引用sorted的版本
Foo Foo::sorted() const &
{
	cout << "Foo Foo::sorted() const &" << endl;

	return Foo(*this).sorted();
}

// 返回一个引用；retFoo1调用是一个左值
Foo &retFoo1()
{
	static Foo foo;
	return foo;
}

// 返回一个值；retFoo2调用是一个右值
Foo retFoo2()
{
	return Foo();
}

int main()
{
	// tests

	Foo foo;
	foo.sorted();

	return 0;
}
