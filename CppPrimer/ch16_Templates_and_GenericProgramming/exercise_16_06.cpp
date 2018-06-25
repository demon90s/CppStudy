// 练习16.6：你认为接受一个数组实参的标准库函数begin和end是如何工作的？定义
// 你自己版本的begin和end。

// begin返回数组首元素的地址，end返回数组最后一个元素后一个位置的地址

#include <iostream>

using namespace std;

template<typename T, unsigned N>
T* arr_beg(T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T* arr_end(T (&arr)[N])
{
	return arr + N;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	auto beg = arr_beg(arr), end = arr_end(arr);

	while (beg != end)
	{
		cout << *beg++ << endl;
	}

	return 0;
}
