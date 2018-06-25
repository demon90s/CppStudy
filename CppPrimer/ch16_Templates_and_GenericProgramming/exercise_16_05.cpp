// 练习16.5：为6.2.4节（第195页）中的print函数编写模板版本，它接受一个数组的引用，
// 能处理任意大小、任意元素类型的数组。

#include <iostream>

using namespace std;

template<typename T, unsigned N>
void print(T (&arr)[N])
{
	for (const auto &elem : arr)
		cout << elem << endl;
}

int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	print(arr1);

	cout << endl;
	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	print(arr2);

	return 0;
}
