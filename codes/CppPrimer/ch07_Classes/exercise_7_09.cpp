/*
 * 练习7.9：对于7.1.2节（第233页）练习中的代码，添加读取和打印Person对象的操作。
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

struct Person
{
	std::string GetName() const { return name; }
	std::string GetAddr() const { return addr; }

	std::string name;
	std::string addr;
};

std::istream& read_person(std::istream &is, Person &person);
std::ostream& print_person(std::ostream &os, const Person &person);

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
	return 0;
}
