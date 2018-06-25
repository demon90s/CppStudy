#include "StrBlob.h"

bool operator==(const StrBlob &rhs, const StrBlob &lhs)
{
	return *rhs.data == *lhs.data;	
}

bool operator!=(const StrBlob &rhs, const StrBlob &lhs)
{
	return !(rhs == lhs);
}

bool operator<(const StrBlob &rhs, const StrBlob &lhs)
{
	return *rhs.data < *lhs.data;
}
