/*
 * 书本里一些小的实用性代码，摘录下来，以备日后使用。
 */

#ifndef UTILITY_H
#define UTILITY_H

#include <iterator>

// 求数组的元素的数量，得到的是一个ptrdiff_t（p107）
#define ARRAY_ITEM_NUM1(arr) (std::end(arr) - std::begin(arr))

// 求数组的元素的数量，得到的是一个constexpr size_t（p140）
#define ARRAY_ITEM_NUM2(arr) (sizeof(arr) / sizeof(*arr))

// 使用移位运算符，设置、清除、判断比特位（p138）
void SetBit(unsigned long *flag, size_t bit);
void ClearBit(unsigned long *flag, size_t bit);
bool IsBitSet(const unsigned long *flag, size_t bit);

#endif
