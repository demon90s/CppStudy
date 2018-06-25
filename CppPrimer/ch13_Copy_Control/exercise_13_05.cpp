// 练习13.5：给定下面的类框架，编写一个拷贝构造函数，拷贝所有成员
// 你的构造函数应该动态分配一个新的string（参见12.1.2节，第407页
// ），并将对象拷贝到ps指向的位置，而不是ps本身的位置。

#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr &hp) :
		ps(new std::string(*hp.ps)), i(hp.i) {}
private:
	std::string *ps;
	int i;
};

int main()
{
	return 0;
}
