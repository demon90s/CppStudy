#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <iostream>

// 为书店程序设定的异常类
class out_of_stock : public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s) : std::runtime_error(s) {}
};

class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s) : std::logic_error(s) {}
	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):
		std::logic_error(s), left(lhs), right(rhs) {}

	const char* what() const noexcept override { static const std::string res("isbn not equal: " + left + " != " + right); return res.c_str(); }

	const std::string left, right;
};

#endif // EXCEPTIONS_H
