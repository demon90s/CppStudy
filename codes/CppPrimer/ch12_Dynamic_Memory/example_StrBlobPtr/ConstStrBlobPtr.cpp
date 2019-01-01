#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}
