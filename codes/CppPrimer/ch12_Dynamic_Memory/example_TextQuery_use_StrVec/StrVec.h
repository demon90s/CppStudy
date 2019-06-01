#ifndef STR_VEC_H
#define STR_VEC_H

#include <string>

class StrVec
{
public:
	StrVec() :	// allocator成员进行默认初始化
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const std::initializer_list<std::string>&);
	StrVec(const StrVec&);						// 拷贝构造函数
	StrVec& operator=(const StrVec&);			// 拷贝赋值运算符
	~StrVec();									// 析构函数
	void push_back(const std::string&);			// 拷贝元素
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t n);
	void resize(size_t n);
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

private:
	static std::allocator<std::string> alloc;	// 分配元素
	// 被添加元素的函数所使用
	void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	std::pair<std::string*, std::string*> alloc_n_copy
		(const std::string*, const std::string*);
	void free();								// 销毁元素并释放内存
	void reallocate();							// 获得更多内存并拷贝已有元素
	
	std::string *elements;						// 指向数组首元素的指针
	std::string *first_free;					// 指向数组第一个空闲元素的指针
	std::string *cap;							// 指向数组尾后位置的指针

};

#endif // STR_VEC_H
