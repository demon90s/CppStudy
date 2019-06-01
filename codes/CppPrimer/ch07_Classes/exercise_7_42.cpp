/*
 * 练习7.42：对于你在练习7.40（参见7.5.1节，第261页）中编写的类，确定哪些构造
 * 函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表
 * 中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。
 */

/*
 * 比如选择Book
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Book
{
public:
	Book(unsigned no, const std::string &name, const std::string &auther, const std::string &pubdate) : m_no(no), m_name(name), m_auther(auther), m_pubdate(pubdate) {}
	Book() : Book(0, "", "", "") {}
	Book(std::istream &is) : Book() { is >> m_no >> m_name >> m_auther >> m_pubdate; }

	void print() { std::cout << m_no << " " << m_name << " " << m_auther << " " << m_pubdate << std::endl; }

	operator bool() const { return m_no != 0; }

private:
	unsigned m_no = 0;
	std::string m_name;
	std::string m_auther;
	std::string m_pubdate;
};

int main()
{
	Book b1; // 默认构造函数，使用类内初始值初始化成员
	b1.print();

	Book b2(1, "c--primer", "someone", "2017.11.8"); // 需要使用一个构造函数来初始化所有成员
	b2.print();

	Book b3(std::cin); // 需要使用一个构造函数从标准输入读入数据来初始化类对象
	b3.print();
	if (!b3)
	{
		cout << "b3 is invalid" << endl;
	}

	return 0;
}
