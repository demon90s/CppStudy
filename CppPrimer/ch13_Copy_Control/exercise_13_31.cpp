// 练习13.31：为你的HasPtr类定义一个<运算符，并定义一个HasPtr的vector。
// 为这个vector添加一些元素，并对它执行sort。注意何时会调用swap。

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

	HasPtr& operator=(HasPtr hp);

	bool operator<(const HasPtr &rhs) const { return *ps > *rhs.ps; }

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

HasPtr& HasPtr::operator=(HasPtr hp)
{
	swap(*this, hp);
	return *this;
}

int main()
{
	std::vector<HasPtr> vec;
	vec.emplace_back("A");
	vec.emplace_back("B");
	vec.emplace_back("C");

	cout << "before sort ..." << endl;
	for (const auto &i : vec)
		cout << i.Value() << " ";
	cout << endl;

	sort(vec.begin(), vec.end());
	cout << "after sort ..." << endl;
	for (const auto &i : vec)
		cout << i.Value() << " ";
	cout << endl;

	return 0;
}
