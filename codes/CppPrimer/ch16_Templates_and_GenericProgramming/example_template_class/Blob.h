#ifndef BLOB_H
#define BLOB_H

#include <vector>
#include <memory>
#include <stdexcept>
#include "BlobPtr.h"

// 前置声明，在Blob中声明友元所需要的
template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {
	// 每个Blob实例将访问权限授予用相同类型实例化的BlobPtr和相等运算符
	friend class BlobPtr<T>;
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	// 构造函数
	Blob() : data(new std::vector<T>()) {}
	Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}
	template<typename It> Blob(It beg, It end);

	// Blob中的元素数目
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	// 添加和删除元素
	void push_back(const T &t) { data->push_back(t); }
	void pop_back();

	// 移动版本
	void push_back(T &&t) { data->push_back(std::move(t)); }

	// 元素访问
	const T& back() const;	
	const T& front() const;	
	const T& operator[](size_type i) const;
	T& back();
	T& front();
	T& operator[](size_type i);

	BlobPtr<T> begin() { return BlobPtr<T>(*this); }
	BlobPtr<T> end() { return BlobPtr<T>(*this, data->size()); }

private:
	std::shared_ptr<std::vector<T>> data;

	// 若data[i]无效，则抛出异常
	void check(size_type i, const std::string &msg) const;
};

template<typename T>
template<typename It>
inline Blob<T>::Blob(It beg, It end) try : data(std::make_shared<std::vector<T>>(beg, end))
{
} catch (const std::bad_alloc &e) { 
	// 构造函数异常处理，见p689
	// 简单处理，直接异常退出
	std::cout << "bad_alloc: " << e.what() << std::endl;
	abort();
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

template<typename T>
inline T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T& Blob<T>::front()
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
inline const T& Blob<T>::back() const
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline const T& Blob<T>::front() const
{
	check(0, "front on empty Blob");
	return data->front();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
	// 如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline const T& Blob<T>::operator[](size_type i) const
{
	// 如果i太大，check会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

#endif
