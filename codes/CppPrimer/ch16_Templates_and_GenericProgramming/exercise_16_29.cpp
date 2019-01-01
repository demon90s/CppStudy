// 练习16.29：修改你的Blob类，用你自己的shared_ptr代替标准库中的版本。

#include <iostream>
#include <vector>
#include "./example_SmartPointer/SharedPtr.h"

using namespace std;

template<typename> class Blob;

template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template<typename T>
class Blob {
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;

	// 构造函数
	Blob() : data(new std::vector<T>()) {}
	Blob(std::initializer_list<T> il) : data(new std::vector<T>(il)) {}

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

private:
	SharedPtr<std::vector<T>> data;

	// 若data[i]无效，则抛出异常
	void check(size_type i, const std::string &msg) const;
};

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

int main()
{
	Blob<int> blob{1, 2, 3, 4, 5};
	Blob<int> blob2(blob);
	blob2.push_back(100);

	for (size_t i = 0; i < blob.size(); ++i)
		cout << blob[i] << endl;

	return 0;
}
