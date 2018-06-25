// 练习13.19：你的Employee类需要定义它自己的拷贝控制成员吗？如果需要，为什么？
// 如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。

// 我认为不需要，认为一个员工实体应该是唯一的。

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
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
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

	//Employee e2(e); // 编译不通过

	return 0;
}
