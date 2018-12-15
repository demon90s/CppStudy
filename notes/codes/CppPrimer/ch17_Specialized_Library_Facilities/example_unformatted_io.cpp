// example: 未格式化IO（p673）

#include <iostream>

using namespace std;

// 单字节操作
void func1()
{
	char ch;
	while (cin.get(ch))
		cout.put(ch);
}

int main()
{
	func1();

	return 0;
}
