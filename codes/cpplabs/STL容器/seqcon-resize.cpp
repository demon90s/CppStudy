/*
	顺序容器通用操作 resize

	resize(n)
	resize(n, t)
	修改容器大小, 如果新的大小要比旧的大, 那么新的元素执行值初始化或者初始化为t, 旧元素不变.
	如果新的大小要比旧的小, 那么后面的元素被删掉.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a = "Hello";
	a.resize(3);

	cout << a.length() << " " << a << endl;		// 3 Hel
	
	a.resize(5, 'X');
	cout << a.length() << " " << a << endl;		// 5 HelXX

	return 0;
}
