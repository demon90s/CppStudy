#include "utility.h"
#include <iostream>
#include <cstddef>

using namespace std;

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

void test_str_replace()
{
	string str = "hello world hello cpp hello utility";
	int cnt = 0;

	cnt = str_replace(str, "hello", "hi");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;

	cnt = str_replace(str, "iii", "hi");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;

	cnt = str_replace(str, "hi world hi cpp hi utility", "wow");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;

	cnt = str_replace(str, "wows", "hi");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;

	cnt = str_replace(str, "", "hi");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;

	cnt = str_replace(str, "wow", "");
	cout << "cnt: " << cnt << ", "
	     << "str: " << str << endl;
}

int main()
{
	// 测试求数组元素的数量
	//test_ARRAY_ITEM_NUM();

	// 测试设置、清除、判断比特位
	//test_bitwise_operator(); 
	
	test_str_replace();

	return 0;
}
