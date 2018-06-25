/*
 * 练习13.53：从底层效率的角度看，HasPtr的赋值运算符并不理想，解释为什么。
 * 为HasPtr实现一个拷贝赋值运算符和一个移动赋值运算符，并比较你的新的移动
 * 赋值运算符中执行的操作和拷贝并交换版本中执行的操作。
 */


// 因为operator=函数中，初始化形参会调用一次拷贝构造函数。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);

public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {}

	//HasPtr& operator=(HasPtr hp);
	HasPtr& operator=(const HasPtr &hp);
	HasPtr& operator=(HasPtr &&hp) noexcept;

	bool operator<(const HasPtr &rhs) const { return *ps > *rhs.ps; }

	~HasPtr() { if (ps) delete ps; }

	std::string Value() const { return *ps; }
private:
	std::string *ps;
	int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
	cout << "swap(HasPtr &lhs, HasPtr &rhs)" << endl;

	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

/*
HasPtr& HasPtr::operator=(HasPtr hp)
{
	swap(*this, hp);
	return *this;
}
*/

HasPtr& HasPtr::operator=(const HasPtr &hp)
{
	cout << "HasPtr& HasPtr::operator=(const HasPtr &hp)" << endl;

	if (ps) {
		delete ps;
	}
	ps = new std::string(*hp.ps);
	i = hp.i;
	return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&hp) noexcept
{
	cout << "HasPtr& HasPtr::operator(HasPtr &&hp)" << endl;

	if (ps) {
		delete ps;
	}
	ps = hp.ps;
	i = hp.i;
	hp.ps = nullptr;
	return *this;
}

int main()
{
	HasPtr a("A");
	HasPtr b("B");
	HasPtr c("C");

	b = a;
	cout << b.Value() << endl;

	b = std::move(c);
	cout << b.Value() << endl;

	return 0;
}
