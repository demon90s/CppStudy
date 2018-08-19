// 条款03：尽可能使用const

#ifndef __RULE03_H__
#define __RULE03_H__

#include <vector>
#include <string>
#include <iostream>
#include <cstring>

extern void Rule03();

// const与指针
inline void Const_And_Pointer()
{
	char greeting[] = "Hello";
	
	char *p = greeting;					// non-const pointer, non-const data
	const char *lcp = greeting;			// non-const pointer, const data(low-level const)
	char *const tcp = greeting;			// const pointer, non-const data(top-level const)
	const char* const cp = greeting;	// const pointer, const data
}

// const与迭代器
inline void Const_And_Iterator()
{
	std::vector<int> vec{1, 2, 3, 4};

	const std::vector<int>::iterator iter = vec.begin();	// iter的作用像个T *const
	*iter = 10;				// 没问题，改变iter所指物
	///++iter;				// 错误！iter是const

	std::vector<int>::const_iterator citer = vec.begin();	// iter的作用像个const T*
	//*citer = 10;			// 错误！*citer是const
	++citer;				// 没问题，改变citer
}

// const成员函数
class TextBlock {
public:
	TextBlock(const char* _text) : text(_text) {}

	const char& operator[](std::size_t position) const		// operator[] for const对象
	{ return text[position]; }

	char& operator[](std::size_t position)					// operator[] for non-const对象
	{ return text[position]; }

private:
	std::string text;
};

inline void Use_TextBlock()
{
	TextBlock tb("Hello");
	std::cout << tb[0];		// 调用non-const TextBlock::operator[]
	tb[0] = 'x';			// 没问题：写一个non-const TextBlock

	const TextBlock ctb("Hello");
	std::cout << ctb[0];	// 调用const TextBlock::operator[]
	//ctb[0] = 'x';			// 错误！写一个const TextBlock（企图对一个const char&赋值）
}

// 在const和non-const成员函数中避免重复
class CTextBlock
{
public:
	CTextBlock(const char *text) : pText(new char[strlen(text) + 1]()) { strcpy(pText, text); }
	~CTextBlock() { delete []pText; }

	const char& operator[](std::size_t position) const
	{
		// ... 边界检查 bounds checking
		// ... 日志数据访问 log access data
		// ... 检验数据完整性 verify data integrity
		return pText[position];
	}

	char &operator[](std::size_t position)
	{
		// 调用const版本的函数
		return const_cast<char&>(
			static_cast<const CTextBlock&>(*this)[position]
			);
	}

private:
	char *pText;
};

inline void Use_CTextBlock()
{
	CTextBlock tb("Hello");
	std::cout << tb[0];
	tb[0] = 'x';

	const CTextBlock ctb("Hello");
	std::cout << ctb[0];
}

#endif // __RULE03_H__
