#include "utility.h"
#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

void test_ARRAY_ITEM_NUM()
{
	int arr[7 * 8] = {};
	//ptrdiff_t sz = ARRAY_ITEM_NUM1(arr);
	constexpr size_t sz = ARRAY_ITEM_NUM2(arr);
	cout << "arr sz: " << sz << endl;
}

void test_bitwise_operator()
{
	unsigned long quizl = 0;
	SetBit(&quizl, 27);
	if (IsBitSet(&quizl, 27))
		cout << "bit is set" << endl;
	else
		cout << "bit is not set" << endl;

	ClearBit(&quizl, 27);
	if (IsBitSet(&quizl, 27))
		cout << "bit is set" << endl;
	else
		cout << "bit is not set" << endl;
}

int main()
{
	// 测试求数组元素的数量
	test_ARRAY_ITEM_NUM();

	// 测试设置、清除、判断比特位
	//test_bitwise_operator(); 

	return 0;
}
