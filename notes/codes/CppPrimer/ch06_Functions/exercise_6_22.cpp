/*
 * 练习6.22：编写一个函数，令其交换两个int指针。
 */

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void swap(int* &a, int* &b)
{
	int *tmp = b;
	b = a;
	a = tmp;
}

int main()
{
	int a = 1, b = 2;
	int *pa = &a, *pb = &b;

	cout << *pa << " " << *pb << endl;
	swap(pa, pb);
	cout << *pa << " " << *pb << endl;

	return 0;
}
