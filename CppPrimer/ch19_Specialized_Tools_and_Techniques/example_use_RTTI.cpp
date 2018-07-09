// example: 使用RTTI（p733）

#include <typeinfo>
#include <iostream>

class Base {
	friend bool operator==(const Base&, const Base&);
public:
	// Base的接口成员

protected:
	virtual bool equal(const Base& rhs) const
	{
		// 执行Base对象的操作
		return m_type == rhs.m_type;
	}

private:
	int m_type = 0;
};

class Derived : public Base {
public:
	// Derived的其他接口成员

protected:
	bool equal(const Base& rhs) const override
	{
		// 我们清除这两个类型是相等的，所以转换过程不会抛出异常
		auto r = dynamic_cast<const Derived&>(rhs);
		return m_id == r.m_id;
	}

private:
	int m_id = 0;
};

// 类型敏感的相等运算符
bool operator==(const Base &lhs, const Base &rhs)
{
	// 如果typeid不相同，返回false，否则虚调用equal
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main()
{
	Derived d1, d2;
	Base b;

	if (b == d1)
	{
		std::cout << "b == di" << std::endl;
	}

	if (d1 == d2)
	{
		std::cout << "d1 == d2" << std::endl;
	}

	return 0;
}
