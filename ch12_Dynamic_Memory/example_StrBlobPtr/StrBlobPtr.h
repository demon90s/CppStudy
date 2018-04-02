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

public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0); 

	std::string &deref() const;
	StrBlobPtr &incr(); // 前缀递增

	std::string& operator[](size_t);
	const std::string& operator[](size_t) const;

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

// 前缀递增，返回递增后的对象的引用
inline StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

#endif
