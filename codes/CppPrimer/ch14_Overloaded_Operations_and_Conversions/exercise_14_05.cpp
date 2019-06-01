/*
 * 练习14.5：在7.5.1节的练习7.40（第261页）中，编写了下列类中某一个的框架，
 * 请问在这个类中应该定义重载的运算符吗？如果是，请写出来。
 */


/*
 * 练习7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要
 * 哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
 */

/*
 * 比如选择Book，这里可以定义输入输出运算符
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Book
{
	friend std::ostream& operator<<(std::ostream &os, const Book &rhs);
	friend std::istream& operator>>(std::istream &is, Book &rhs);

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

std::ostream& operator<<(std::ostream &os, const Book &rhs)
{
	os << rhs.m_no << " " << rhs.m_name << " " << rhs.m_auther << " " << rhs.m_pubdate;
	return os;
}

std::istream& operator>>(std::istream &is, Book &rhs)
{
	is >> rhs.m_no >> rhs.m_name >> rhs.m_auther >> rhs.m_pubdate;
	if (!is)
		rhs = Book();

	return is;
}

int main()
{
	Book b1; // 默认构造函数，使用类内初始值初始化成员
	cout << b1 << endl;

	Book b2(1, "c--primer", "someone", "2017.11.8"); // 需要使用一个构造函数来初始化所有成员
	cout << b2 << endl;

	Book b3;
	cin >> b3;
	cout << b3 << endl;

	return 0;
}
