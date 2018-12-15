/*
 * 练习7.15：对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

struct Person
{
	// 构造函数
	Person() = default;
	Person(const std::string &_name, const std::string &_addr) :
	       name(_name), addr(_addr) {}
	Person(std::istream &is);

	std::string GetName() const { return name; }
	std::string GetAddr() const { return addr; }

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
