#ifndef MAKE_SHARED_H
#define MAKE_SHARED_H

#include <memory>

template <typename T, typename... Args> inline
std::shared_ptr<T> MakeShared(Args&&... args)
{
	auto p = new T(std::forward<Args>(args)...);
	return std::shared_ptr<T>(p);
}

#endif
