/*
 * 练习7.19：在你的Person类中，你将把哪些成员声明成public的？
 * 解释你这样做的原因。
 */

// 见下面修改的Person类。构造函数和Get函数都要被用户代码所使用，
// 因此应该是public的。而数据成员属于实现细节，需要被隐藏，所以
// 是private的。

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

struct Person
{
//public: 如果使用了访问控制说明符，还需要声明相关友元函数
	// 构造函数
	Person() = default;
	Person(const std::string &_name, const std::string &_addr) :
	       name(_name), addr(_addr) {}
	Person(std::istream &is);

	std::string GetName() const { return name; }
	std::string GetAddr() const { return addr; }

//private:
	std::string name;
	std::string addr;
};

std::istream& read_person(std::istream &is, Person &person);
std::ostream& print_person(std::ostream &os, const Person &person);

Person::Person(std::istream &is)
{
	read_person(is, *this);
}

std::istream& read_person(std::istream &is, Person &person)
{
	is >> person.name >> person.addr;
	return is;
}

std::ostream& print_person(std::ostream &os, const Person &person)
{
	os << person.name << " "
	   << person.addr;

	return os;
}

int main()
{
	Person p1("liudiwen", "Guangzhou");
	print_person(cout, p1) << endl;

	Person p2(cin);
	print_person(cout, p2) << endl;

	return 0;
}
