// 条款16：成对使用 new 和 delete 时要采取相同的形式
#ifndef __RULE16_H__
#define __RULE16_H__

#include <string>
#include <iostream>

extern void Rule16();

namespace rule16
{
	inline void bug1()
	{
		// 程序行为未有定义，实际上在 vs 下崩溃
		std::string* stringArray = new std::string[100];

		int *np = (int*)stringArray - 1;	// 前一个字，存放数组长度
		std::cout << *np << std::endl;

		delete stringArray;
	}

	inline void correct()
	{
		std::string* stringPtr1 = new std::string;
		std::string* stringPtr2 = new std::string[100];

		delete stringPtr1;		// 删除一个对象
		delete[] stringPtr2;	// 删除一个又对象组成的数组
	}

	inline void case_typedef()
	{
		// 如果 typedef 了一个数组，那么也要使用 delete[] 删除动态数组
		typedef std::string AddressLines[4];
		std::string *pal = new AddressLines;

		//delete pal;	// 行为未有定义！
		delete[] pal;	// 正确
	}
}

#endif // __RULE16_H__