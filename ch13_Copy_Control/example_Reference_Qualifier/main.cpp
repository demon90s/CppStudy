// example: 引用限定符（p483）

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

// 本对象是const或是一个左值，哪种情况我们都不能对原址排序
Foo Foo::sorted() const &
{
	cout << "Foo Foo::sorted() const &" << endl;

	Foo ret(*this);	// 拷贝一个副本
	sort(ret.data.begin(), ret.data.end()); // 排序副本
	return ret;		// 返回副本
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
	
	Foo i, j;		// i,j是左值
	i = j;			// 正确，i是左值
	retFoo1() = j;	// 正确，retFoo1()返回一个左值
	//retFoo2() = j;	// 错误，retFoo2()返回一个右值
	i = retFoo2();	// 正确，右值可以放在赋值符号的右边

	retFoo1().sorted(); // retFoo1()是一个左值，调用Foo::sorted() const &
	retFoo2().sorted(); // retFoo2()是一个右值，调用Foo::sorted() &&

	return 0;
}
