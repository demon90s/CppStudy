/*
 * 书本里一些小的实用性代码，摘录下来，以备日后使用。
 * 以及一些自己收集的代码
 * 仅使用标准库
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>

// 求数组的元素的数量，得到的是一个ptrdiff_t（p107）
#define ARRAY_ITEM_NUM1(arr) (std::end(arr) - std::begin(arr))

// 求数组的元素的数量，得到的是一个constexpr size_t（p140）
#define ARRAY_ITEM_NUM2(arr) (sizeof(arr) / sizeof(*arr))

// 求数组元素的数量（p583，练习16.7）
template<typename T, size_t N>
size_t ArrayItemNum(T (&arr)[N]) { return N; }

// 进行一次无效的变量使用，以忽略GCC下的未使用变量警告
#define USE_VAR(x) ((void)&(x))

// 使用移位运算符，设置、清除、判断比特位（p138）
void SetBit(unsigned long *flag, size_t bit);
void ClearBit(unsigned long *flag, size_t bit);
bool IsBitSet(const unsigned long *flag, size_t bit);

/*
 * 字符串替换
 * 将s中所有的old_val替换成new_val
 * 返回替换的字符串个数
 */
int str_replace(std::string &s, const std::string &old_val, const std::string &new_val);

/*
 * 从p中读取一个合法的名字，存入name中，成功返回p中最后读取字符的下一个字符的地址，失败返回NULL
 * p是空指针，或者p指向的字符不是一个合法名字的开头字符，都会返回空指针
 * 所谓合法的名字，就是开头是一个字母或者_，后面跟着字母、数字或者下划线的名字
 */
const char *read_name(const char *p, std::string *name);

/*
 * string转换成基础类型，返回是否转换成功
 */
template<typename T>
bool string_to_basetype(const std::string &str, T &val)
{
	std::istringstream iss(str);
	if (iss >> val)
		return true;
	else
		return false;
}

/*
 * 基础类型转换成string，返回是否转换成功
 */
template<typename T>
bool basetype_to_string(T &val, std::string &str)
{
	std::ostringstream oss;
	if (oss << val) {
		str = oss.str();
		return true;
	}
	return false;
}

/*
 * 打印容器中的元素（p595，练习16.20）
 */
template<typename Container>
void print_container(const Container &container)
{
	for (auto it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif
