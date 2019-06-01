#ifndef VEC_H
#define VEC_H

#include <memory>
#include <initializer_list>
#include <algorithm>

template<typename elemType> class Vec;

template<typename elemType>
bool operator==(const Vec<elemType>&, const Vec<elemType>&);

template<typename elemType>
bool operator!=(const Vec<elemType>&, const Vec<elemType>&);

template<typename elemType>
bool operator<(const Vec<elemType>&, const Vec<elemType>&);

template<typename elemType>
class Vec
{
	friend bool operator==<elemType>(const Vec<elemType> &lhs, const Vec<elemType> &rhs);
	friend bool operator!=<elemType>(const Vec<elemType> &lhs, const Vec<elemType> &rhs);
	friend bool operator< <elemType>(const Vec<elemType> &lhs, const Vec<elemType> &rhs);

public:
	inline Vec() :	// allocator成员进行默认初始化
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	inline Vec(const std::initializer_list<elemType>&);
	
	inline Vec(const Vec&);						// 拷贝构造函数
	inline Vec(Vec&&) noexcept;					// 移动构造函数
	inline Vec& operator=(const Vec&);			// 拷贝赋值运算符
	inline Vec& operator=(Vec&&) noexcept;		// 移动赋值运算符
	inline ~Vec();									// 析构函数

	inline Vec& operator=(std::initializer_list<elemType> il);
	inline elemType& operator[](std::size_t n) { return elements[n]; }
	inline const elemType& operator[](std::size_t n) const { return elements[n]; }

	inline void push_back(const elemType&);			// 拷贝元素
	template<typename... Args> inline void emplace_back(Args&&... args);
	inline size_t size() const { return first_free - elements; }
	inline size_t capacity() const { return cap - elements; }
	inline void reserve(size_t n);
	inline void resize(size_t n);
	inline elemType *begin() const { return elements; }
	inline elemType *end() const { return first_free; }

private:
	static std::allocator<elemType> alloc;	// 分配元素
	// 被添加元素的函数所使用
	inline void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	inline std::pair<elemType*, elemType*> alloc_n_copy
		(const elemType*, const elemType*);
	inline void free();								// 销毁元素并释放内存
	inline void reallocate();							// 获得更多内存并拷贝已有元素
	
	elemType *elements;						// 指向数组首元素的指针
	elemType *first_free;					// 指向数组第一个空闲元素的指针
	elemType *cap;							// 指向数组尾后位置的指针
};

template<typename elemType>
std::allocator<elemType> Vec<elemType>::alloc;

template<typename elemType>
Vec<elemType>::Vec(const std::initializer_list<elemType> &lst)
{
	auto newdata = alloc_n_copy(lst.begin(), lst.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename elemType>
Vec<elemType>::Vec(const Vec<elemType> &s)
{
	// 调用alloc_n_copy分配空间以容纳与s中一样多的元素
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

template<typename elemType>
Vec<elemType>::Vec(Vec<elemType> &&s) noexcept
	// 成员初始化器接管s中的资源
	: elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	// 令s进入这样的状态：对其进行析构函数是安全的
	s.elements = s.first_free = s.cap = nullptr;
}

template<typename elemType>
Vec<elemType>& Vec<elemType>::operator=(Vec<elemType> &&rhs) noexcept
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

template<typename elemType>
bool operator==(const Vec<elemType> &lhs, const Vec<elemType> &rhs)
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

template<typename elemType>
bool operator!=(const Vec<elemType> &lhs, const Vec<elemType> &rhs)
{
	return !(lhs == rhs);
}

template<typename elemType>
bool operator<(const Vec<elemType> &lhs, const Vec<elemType> &rhs)
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

template<typename elemType>
Vec<elemType>::~Vec()
{
	free();
}

template<typename elemType>
Vec<elemType> &Vec<elemType>::operator=(const Vec<elemType> &rhs)
{
	// 调用alloc_n_copy分配内存，大小与rhs中元素占用空间一样多
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename elemType>
Vec<elemType> &Vec<elemType>::operator=(std::initializer_list<elemType> il)
{
	// alloc_n_copy分配内存空间并从给定范围内拷贝元素
	auto data = alloc_n_copy(il.begin(), il.end());
	free();					// 销毁对象中的元素并释放内存空间
	elements = data.first;	// 更新数据成员使其指向新空间
	first_free = cap = data.second;
	return *this;
}

template<typename elemType>
void Vec<elemType>::push_back(const elemType &s)
{
	chk_n_alloc(); // 确保有空间容纳新元素
	// 在first_free指向的元素中构造s的副本
	alloc.construct(first_free++, s);
}

template<typename elemType>
template<typename... Args>
void Vec<elemType>::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

template<typename elemType>
std::pair<elemType*, elemType*>
Vec<elemType>::alloc_n_copy(const elemType *b, const elemType *e)
{
	// 分配空间保存给定范围中的元素
	auto data = alloc.allocate(e - b);

	// 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
	return {data, uninitialized_copy(b, e, data)};
}

template<typename elemType>
void Vec<elemType>::free()
{
	// 不能传递给deallocate一个空指针，如果elements为0，函数什么也不做
	if (elements) {
		// 逆序销毁旧元素
		
		//for (auto p = first_free; p != elements;) alloc.destroy(--p);

		std::for_each(elements, first_free, [this](elemType &s){ alloc.destroy(&s); } );

		alloc.deallocate(elements, cap - elements);
	}
}

template<typename elemType>
void Vec<elemType>::reallocate()
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

template<typename elemType>
void Vec<elemType>::reserve(size_t n)
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

template<typename elemType>
void Vec<elemType>::resize(size_t n)
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
		reallocate();

		do {
			chk_n_alloc();

			alloc.construct(first_free++);
		} while (first_free != elements + n);

		return;
	}
}

#endif // VEC_H
