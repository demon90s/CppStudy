// 练习13.30：为你的类值版本的HasPtr编写swap函数，并测试它。为你的swap函数
// 添加一个打印语句，指出函数什么时候执行。

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);

public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {}

	HasPtr& operator=(const HasPtr &hp) {
		auto new_ps = new std::string(*hp.ps);
		delete ps;
		ps = new_ps;
		i = hp.i;
		return *this;
	}

	~HasPtr() { delete ps; }

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

int main()
{
	HasPtr p1("p1"), p2("p2");
	swap(p1, p2);

	cout << "p1: " << p1.Value() << endl;
	cout << "p2: " << p2.Value() << endl;

	return 0;
}
