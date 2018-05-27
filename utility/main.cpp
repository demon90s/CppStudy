#include "utility.h"
#include <iostream>
#include <cstddef>
#include "ArrayFuncs.h"

using namespace std;

void test_ARRAY_ITEM_NUM()
{
	int arr[7 * 8] = {};
	//ptrdiff_t sz = ARRAY_ITEM_NUM1(arr);
	//constexpr size_t sz = ARRAY_ITEM_NUM2(arr);
	auto sz = ArrayItemNum(arr);

	cout << "arr sz: " << sz << endl;
}

void test_bitwise_operator()
{
	constexpr size_t bit = 63;

	unsigned long quizl = 0;
	SetBit(&quizl, bit);
	if (IsBitSet(&quizl, bit))
		cout << "bit is set" << endl;
	else
		cout << "bit is not set" << endl;

	ClearBit(&quizl, bit);
	if (IsBitSet(&quizl, bit))
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

void test_read_name()
{
	string name;
	char str[] = "demon90s@163.com";

	const char *p = str;
	p = read_name(p, &name);
	if (p) {
		cout << name << endl;
		cout << p << endl;
	}

	p = read_name(p, &name);
	if (!p)
		cout << "p is nullptr" << endl;
}

void test_string_to_basetype()
{
	string s = "12345";
	int a = 0;
	if (string_to_basetype(s, a))
		cout << a << endl;

	double pi = 3.14;
	if (basetype_to_string(pi, s))
		cout << s << endl;
}

int main()
{
	// 测试求数组元素的数量
	//test_ARRAY_ITEM_NUM();

	// 测试设置、清除、判断比特位
	//test_bitwise_operator(); 
	
	//test_str_replace();
	
	//test_read_name();
	
	//test_string_to_basetype();
	
	utility::Test_ArrayFuncs();

	return 0;
}
