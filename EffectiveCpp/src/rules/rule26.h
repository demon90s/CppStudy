// 条款26：尽可能延后变量定义式的出现时间
#ifndef __RULE26_H__
#define __RULE26_H__

#include <string>
#include <stdexcept>

inline void Rule26()
{
	// 对于循环，考虑变量的定义位置（通常用第二种，第一种程序的可理解性和可维护性不好）

	// 1个析构函数 + 1个构造函数 + n个赋值操作
	{
		std::string s;
		for (int i = 0; i < 10; ++i) {
			s = std::to_string(i);
		}
	}
	
	// n个构造函数 + n个析构函数
	{
		for (int i = 0; i < 10; ++i) {
			std::string s = std::to_string(i);
		}
	}
}

namespace rule26
{
	const int MinimumPasswordLength = 10;

	// 这个函数过早地定义变量“encrypted”
	// 如果异常被抛出，仍要付出 encrypted 的构造和析构成本
	inline std::string encryptPassword_bad(const std::string& password)
	{
		using namespace std;
		string encrypted;
		if (password.length() < MinimumPasswordLength) {
			throw logic_error("password is too short");
		}

		// 加密 ...
		return encrypted;
	}

	// 延后 encrypted 的定义，直到真正需要它
	inline std::string encryptPassword_good(const std::string& password)
	{
		using namespace std;
		if (password.length() < MinimumPasswordLength) {
			throw logic_error("password is too short");
		}

		string encrypted(password); // 拷贝初始化 比 defalut-construct + 赋值操作 效率高
		// 加密 ...
		return encrypted;
	}
}

#endif // __RULE26_H__