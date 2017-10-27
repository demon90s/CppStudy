// example: 返回数组指针（使用decltype，p206）

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// 指向5个整数的数组的类型别名
using arrT = int[5];

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

// 返回一个指针，该指针指向含有5个整数的数组
decltype(odd) *arrPtr(int i)
{
	return (i % 2) ? &odd : &even;
}

int main()
{
	arrT *arr = arrPtr(1);

	for (auto i : *arr)
		cout << i << " ";
	cout << endl;

	return 0;
}
