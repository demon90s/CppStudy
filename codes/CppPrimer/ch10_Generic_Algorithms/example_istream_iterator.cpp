// example: istream_iterator操作（p359）

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void test1()
{
	istream_iterator<int> int_it(cin);	// 从cin读取int
	istream_iterator<int> int_eof;		// 尾后迭代器
	vector<int> vec;

	while (int_it != int_eof)
		// 后置递增运算符读取流，返回迭代器的旧值
		// 解引用迭代器，获得从流读取的前一个值
		vec.push_back(*int_it++);

	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

// 使用 istream_iterator 快速地读取元素入容器
void test2()
{
	vector<int> vec {istream_iterator<int>(cin), istream_iterator<int>()};

	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}

int main()
{
	//test1();
	test2();

	return 0;
}
