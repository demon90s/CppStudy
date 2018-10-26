#include <cstring>

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>

#include "String.h"

using namespace std;

std::ostream& operator<<(std::ostream &os, String &rhs)
{
	auto str = unique_ptr<char[]>(new char[rhs.size() + 1]());
	memcpy(str.get(), rhs.elements, rhs.size());
	os << str.get();
	return os;
}

allocator<char> String::alloc;

String::String(const initializer_list<char> &lst)
{
	auto newdata = alloc_n_copy(lst.begin(), lst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(const char *str)
{
	if (!str) return;

	auto newdata = alloc_n_copy(str, str + strlen(str));
	elements = newdata.first;
	first_free = cap = newdata.second;
}

String::String(const String &s)
{
	// 调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;

	cout << "String::String(const String &s)" << endl;
}

String::String(String &&s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;

	cout << "String::String(String &&s) noexcept" << endl;
}

String::~String()
{
	free();
}

String &String::operator=(String &&rhs) noexcept
{
	if (this != &rhs) {
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;

		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

bool operator==(const String &lhs, const String &rhs)
{
	auto lhs_beg = lhs.elements;
	auto rhs_beg = rhs.elements;

	while (lhs_beg != lhs.first_free && rhs_beg != rhs.first_free) {
		if (*lhs_beg != *rhs_beg)
			return false;

		++lhs_beg;
		++rhs_beg;
	}

	if (lhs_beg == lhs.first_free && rhs_beg == rhs.first_free)
		return true;

	return false;
}

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
}

String &String::operator=(const String &rhs)
{
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;

	cout << "String &String::operator=(const String &rhs)" << endl;
	return *this;
}

String& String::operator=(const char *str)
{
	if (str) {

		auto data = alloc_n_copy(str, str + strlen(str));
		free();
		elements = data.first;
		first_free = cap = data.second;
	}
	return *this;
}

bool operator<(const String &lhs, const String &rhs)
{
	auto lhs_beg = lhs.elements;
	auto rhs_beg = rhs.elements;

	while (lhs_beg != lhs.first_free && rhs_beg != rhs.first_free) {
		if (*lhs_beg > *rhs_beg)
			return false;
		else if (*lhs_beg < *rhs_beg)
			return true;

		++lhs_beg;
		++rhs_beg;
	}

	if (lhs_beg == lhs.first_free && rhs_beg <= rhs.first_free)
		return true;

	return false;
}

void String::push_back(const char &s)
{
	chk_n_alloc(); // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);

	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return {data, uninitialized_copy(b, e, data)};
}

void String::free()
{
	// 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁旧元素
		
		//for (auto p = first_free; p != elements;) alloc.destroy(--p);

		for_each(elements, first_free, [this](char &s){ alloc.destroy(&s); } );

		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
{
	// 我们将分配当前大小两倍的内存空间
	auto newcapacity = size() ? 2 * size() : 1;
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 将数据从旧内存移动到新内存
	auto dest = newdata;  // 指向新数组中下一个空闲位置
	auto elem = elements; // 指向旧数组中下一个元素
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free(); // 一旦我们移动完元素就释放旧内存空间
	// 更新我们的数据结构，执行新元素
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void String::reserve(size_t n)
{
	if (n <= capacity()) return;

	auto newdata = alloc.allocate(n);

	// copy old data
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();

	elements = newdata;
	first_free = dest;
	cap = elements + n;
}

void String::resize(size_t n)
{
	if (n == size()) return;

	if (n < size())
	{
		do {
			alloc.destroy(--first_free);
		} while (first_free != elements + n);

		return;
	}

	if (n > size())
	{
		do {
			chk_n_alloc();

			alloc.construct(first_free++);
		} while (first_free != elements + n);

		return;
	}
}
