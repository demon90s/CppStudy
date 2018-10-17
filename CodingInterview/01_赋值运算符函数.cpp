/*
 * 面试题1：赋值运算符函数
 *
 * 题目：如下为类型 CMyString 的声明，请为该类型添加赋值运算符函数。
 */

/*
 * 考察点：
 *
 * 1. 函数的声明，为什么是该类型的引用？（为了可以连续赋值） 
 * 2. 函数的参数，为什么是该类型的常量引用？（使用引用为了避免拷贝开销，不会改变实参状态因此使用常引用）
 * 3. 是否有释放自身内存，避免内存泄露。
 * 4. 当发生自赋值的时候，是否正常赋值。
 * 5. 异常安全（当内存不足，new抛出异常时）
 */

/*
 * 测试用例：
 *
 * 1. 正常赋值（一个实例赋值给另一个）
 * 2. 自赋值
 * 3. 连续赋值
 */

class CMyString
{
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	// 赋值运算符的实现
	CMyString& operator=(const CMyString& str)
	{
		CMyString tmp(str);
		char *tmp_p = m_pData;
		m_pData = tmp.m_pData;
		tmp.m_pData = tmp_p;
		return *this;
	}

	const char* CStr() const { return m_pData; }

private:
	char *m_pData;
};

//========== CMyString 的实现
int strlen(const char* s)
{
	const char* p = s;
	while (*p) ++p;
	return p - s;
}

char* strcpy(char *s, const char* t)
{
	while ((*s++ = *t++) != '\0');
	return s;
}

CMyString::CMyString(const char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int len = strlen(pData);
		m_pData = new char[len + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int len = strlen(str.m_pData);
	m_pData = new char[len + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

//========== 测试用例

#include <iostream>

// 正常赋值
void Test1()
{
	CMyString str1("Hello World");
	CMyString str2;

	str2 = str1;

	std::cout << "str1: " << str1.CStr() << std::endl;
	std::cout << "str2: " << str2.CStr() << std::endl;
}

// 连续赋值
void Test2()
{
	CMyString str1("Hello World");
	CMyString str2, str3;

	str2 = str3 = str1;

	std::cout << "str1: " << str1.CStr() << std::endl;
	std::cout << "str2: " << str2.CStr() << std::endl;
	std::cout << "str3: " << str3.CStr() << std::endl;
}

// 自赋值
void Test3()
{
	CMyString str1("Hello World");

	str1 = str1;

	std::cout << "str1: " << str1.CStr() << std::endl;
}

int main()
{
	//Test1();
	//Test2();
	Test3();

	return 0;
}
