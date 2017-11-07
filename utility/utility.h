/*
 * 书本里一些小的实用性代码，摘录下来，以备日后使用。
 * 以及一些自己收集的代码
 * 仅使用标准库
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iterator>

// 求数组的元素的数量，得到的是一个ptrdiff_t（p107）
#define ARRAY_ITEM_NUM1(arr) (std::end(arr) - std::begin(arr))

// 求数组的元素的数量，得到的是一个constexpr size_t（p140）
#define ARRAY_ITEM_NUM2(arr) (sizeof(arr) / sizeof(*arr))

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

#endif
