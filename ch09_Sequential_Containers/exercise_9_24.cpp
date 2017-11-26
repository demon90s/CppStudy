// 练习9.24：编写程序，分别使用at、下标运算符、front和begin提取一个vector中
// 的第一个元素。在一个空的vector上测试你的程序。

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;

	//vec.at(0);    // terminate called after throwing an instance of 'std::out_of_range'

	//cout << vec[0] << endl;    // Segmentation fault (core dumped)

	//cout << vec.front() << endl; // Segmentation fault (core dumped)

	cout << *vec.begin() << endl;  // Segmentation fault (core dumped)

	return 0;
}
