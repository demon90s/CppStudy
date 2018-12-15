#include <memory>
#include <utility>
#include <algorithm>

#include "StrVec.h"

using namespace std;

allocator<std::string> StrVec::alloc;

StrVec::StrVec(const initializer_list<string> &lst)
{
	auto newdata = alloc_n_copy(lst.begin(), lst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &s)
{
	// 调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
	// 成员初始化器接管s中的资源
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// 令s进入这样的状态：对其进行析构函数是安全的
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	// 直接检测自赋值
	if (this != &rhs) {
		free();	// 释放已有元素
		elements = rhs.elements; // 从rhs接管资源
		first_free = rhs.first_free;
		cap = rhs.cap;

		// 将rhs置于可析构状态
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
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

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
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

StrVec::~StrVec()
{
	free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
	// alloc_n_copy分配内存空间并从给定范围内拷贝元素
	auto data = alloc_n_copy(il.begin(), il.end());
	free();					// 销毁对象中的元素并释放内存空间
	elements = data.first;	// 更新数据成员使其指向新空间
	first_free = cap = data.second;
	return *this;
}

void StrVec::push_back(const string &s)
{
	chk_n_alloc(); // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);

	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
	// 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁旧元素
		
		//for (auto p = first_free; p != elements;) alloc.destroy(--p);

		for_each(elements, first_free, [this](string &s){ alloc.destroy(&s); } );

		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
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

void StrVec::reserve(size_t n)
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

void StrVec::resize(size_t n)
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
