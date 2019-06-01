#ifndef __STR_BLOB_PTR_H__
#define __STR_BLOB_PTR_H__

#include <memory>
#include <vector>
#include <string>

class StrBlob;

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend bool operator!=(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend bool operator<(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend StrBlobPtr operator+(const StrBlobPtr &rhs, size_t n);
	friend StrBlobPtr operator-(const StrBlobPtr &rhs, size_t n);

public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0); 

	std::string &deref() const;
	StrBlobPtr &incr(); // 前缀递增

	std::string& operator[](size_t);
	const std::string& operator[](size_t) const;

	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string& operator*() const;
	std::string* operator->() const;

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr; // 保存一个weak_ptr，意味着底层vector可能会被销毁
	std::size_t curr; // 在数组中的当前位置
};


inline std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();	// vector还存在吗？

	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}

	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

inline std::string & StrBlobPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr]; // (*p)是对象所指向的vector
}

inline std::string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "out of range");
	return (*p)[n];
}

inline const std::string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "out of range");
	return (*p)[n];
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
	// 如果curr已经指向了尾后位置，则无法递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;			// 将curr在当前状态下向前移动一个元素
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
	// 如果curr是0，则继续递减它将产生一个无效下标
	--curr;			// 将curr在当前状态下向后移动一个元素
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
	// 此处无须检查有效性，调用前置递增运算时才需要检查
	StrBlobPtr ret = *this;		// 记录当前的值
	++*this;					// 向前移动一个元素，前置++需要检查递增的有效性
	return ret;					// 返回之前记录的状态
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
	// 此处无需检查有效性，调用前置递减运算时才需要检查
	StrBlobPtr ret = *this;		// 记录当前的值
	--*this;					// 向后移动一个元素，前置--需要检查递减的有效性
	return ret;					// 返回之前记录的状态
}

inline std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline std::string* StrBlobPtr::operator->() const
{
	// 将实际工作委托给解引用运算符
	return & this->operator*();
}

// 前缀递增，返回递增后的对象的引用
inline StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

#endif
