// example: 无返回值函数（p200）

#include <iostream>

using std::cout;
using std::endl;

void swap(int &v1, int &v2)
{
	// 如果两个值是相等的，则不需要交换，直接退出
	if (v1 == v2)
		return;

	// 如果函数执行到了这里，说明还需要继续完成某些功能
	int tmp = v2;
	v2 = v1;
	v1 = tmp;
	// 此处无须显式的return语句
}

int main()
{
	int a = 1, b = 2;
	cout << a << " " << b << endl;

	swap(a, b);
	cout << a << " " << b << endl;

	return 0;
}
