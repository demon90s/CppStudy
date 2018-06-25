/*
 * 练习7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要
 * 哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
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
	friend bool operator==(const Book &lhs, const Book &rhs);
	friend bool operator!=(const Book &lhs, const Book &rhs);

public:
	Book() = default;
	Book(unsigned no, const std::string &name, const std::string &auther, const std::string &pubdate) : m_no(no), m_name(name), m_auther(auther), m_pubdate(pubdate) {}
	Book(std::istream &is) { is >> m_no >> m_name >> m_auther >> m_pubdate; }

	void print() { std::cout << m_no << " " << m_name << " " << m_auther << " " << m_pubdate << std::endl; }

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

	if (b2 == b3)
		cout << "b2 == b3" << endl;

	return 0;
}

bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.m_no == rhs.m_no &&
	       lhs.m_name == rhs.m_name &&
		   lhs.m_auther == rhs.m_auther &&
		   lhs.m_pubdate == rhs.m_pubdate;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}
