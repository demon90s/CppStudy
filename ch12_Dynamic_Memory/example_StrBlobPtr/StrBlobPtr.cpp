#include "StrBlobPtr.h"
#include "StrBlob.h"

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

bool operator==(const StrBlobPtr &rhs, const StrBlobPtr &lhs)
{
	return rhs.curr == lhs.curr;
}

bool operator!=(const StrBlobPtr &rhs, const StrBlobPtr &lhs)
{
	return !(rhs == lhs);
}

bool operator<(const StrBlobPtr &rhs, const StrBlobPtr &lhs)
{
	return rhs.curr < lhs.curr;
}

StrBlobPtr operator+(const StrBlobPtr &rhs, size_t n)
{
	auto pos = rhs.curr + n;
	rhs.check(pos, "out of range");
	StrBlobPtr ret = rhs;
	ret.curr = pos;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr &rhs, size_t n)
{
	auto pos = rhs.curr - n;
	rhs.check(pos, "out of range");
	StrBlobPtr ret = rhs;
	ret.curr = pos;
	return ret;
}
