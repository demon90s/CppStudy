// 练习13.11：为前面练习中的HasPtr类添加一个析构函数。

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
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
private:
	std::string *ps;
	int i;
};

int main()
{
	return 0;
}
