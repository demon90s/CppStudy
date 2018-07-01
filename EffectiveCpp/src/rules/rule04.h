// 条款04：确定对象被使用前已被初始化

#ifndef __RULE04_H__
#define __RULE04_H__

#include <iostream>
#include <string>
#include <list>

// 初始化内置类型
inline void Init_BuiltinTyoe()
{
	int x = 0;				// 手工初始化
	const char* text = "A C-style string";

	double d;
	std::cin >> d;			// 以读取input stream的方式完成初始化
}

// 用构造函数初始化列表初始化数据成员
class PhoneNumber { /* ... */ };
class ABEntry {				// ABEntry = "Address Book Entry"
public:
	ABEntry(const std::string &name, const std::string &address, const std::list<PhoneNumber> phones)
		: theName(name),
		theAddress(address),
		thePhones(phones),
		numTimesConsulted(0)
	{}

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

// 用local static对象代替non-local static对象
class FileSystem {
public:
	std::size_t numDisks() const { /* ... */return 0; }		// 众多成员函数之一
};

inline FileSystem& tfs()
{
	static FileSystem fs;
	return fs;
}

class Directory {
public:
	Directory()
	{
		std::size_t disks = tfs().numDisks();
		/* ... */
	}
};

inline Directory& tempDir()
{
	static Directory td;
	return td;
}

extern void Rule04();

#endif // __RULE04_H__