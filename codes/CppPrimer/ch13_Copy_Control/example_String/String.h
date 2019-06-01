#ifndef STRING_H
#define STRING_H

class String
{
	friend std::ostream& operator<<(std::ostream &os, String &rhs);
	friend bool operator==(const String &lhs, const String &rhs);
	friend bool operator!=(const String &lhs, const String &rhs);
	friend bool operator<(const String &lhs, const String &rhs);

public:
	String() :	// allocator成员进行默认初始化
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const std::initializer_list<char>&);
	String(const char*);
	String& operator=(const char*);
	char& operator[](size_t n) { return elements[n]; }
	const char& operator[](size_t n) const { return elements[n]; }

	String(const String&);						// 拷贝构造函数
	String(String&&) noexcept;					// 移动构造函数
	String& operator=(const String&);			// 拷贝赋值运算符
	String& operator=(String&&) noexcept;		// 移动赋值运算符
	~String();									// 析构函数

	void push_back(const char&);				// 拷贝元素
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	void reserve(size_t n);
	void resize(size_t n);
	char *begin() const { return elements; }
	char *end() const { return first_free; }

private:
	static std::allocator<char> alloc;	// 分配元素
	// 被添加元素的函数所使用
	void chk_n_alloc()
		{ if (size() == capacity()) reallocate(); }
	// 工具函数，被拷贝构造函数、赋值运算符和析构函数所使用
	std::pair<char*, char*> alloc_n_copy
		(const char*, const char*);
	void free();								// 销毁元素并释放内存
	void reallocate();							// 获得更多内存并拷贝已有元素
	
	char *elements;						// 指向数组首元素的指针
	char *first_free;					// 指向数组第一个空闲元素的指针
	char *cap;							// 指向数组尾后位置的指针

};

#endif // STRING_H
