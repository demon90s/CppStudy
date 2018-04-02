#ifndef __CONST_STR_BLOB_PTR_H__
#define __CONST_STR_BLOB_PTR_H__

#include <memory>
#include <vector>
#include <string>

class StrBlob;

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0); 

	const std::string &deref() const;
	ConstStrBlobPtr &incr(); // 前缀递增

	const std::string& operator*() const;
	const std::string* operator->() const;

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<std::string>>
	check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr; // 保存一个weak_ptr，意味着底层vector可能会被销毁
	std::size_t curr; // 在数组中的当前位置
};


inline std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();	// vector还存在吗？

	if (!ret)
	{
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}

	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

inline const std::string & ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr]; // (*p)是对象所指向的vector
}

// 前缀递增，返回递增后的对象的引用
inline ConstStrBlobPtr & ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

inline const std::string& ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

inline const std::string* ConstStrBlobPtr::operator->() const
{
	return & operator*();
}

#endif
