// 练习13.18：定义一个Employee类，它包含雇员的姓名和唯一的雇员编号。为这个类
// 定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。每个构造函
// 数应该通过递增一个static数据成员来生成一个唯一的证号。

#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
	Employee() : m_id(id_auto) { gen_id(); }
	Employee(string &name) : m_id(id_auto), m_name(name) { gen_id(); }

	void Print() const { cout << "id: " << m_id << "\tname: " << m_name << endl; }

private:
	static void gen_id() { ++id_auto; }

	static int id_auto;
	int m_id;
	string m_name;
};

int Employee::id_auto = 0;

int main()
{
	string name = "liudiwen";
	Employee e(name);
	e.Print();

	return 0;
}
