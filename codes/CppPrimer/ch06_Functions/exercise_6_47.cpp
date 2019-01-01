/*
 * 练习6.47：改写6.3.2节（第205页）练习中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。
 * 例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。
 */

#include <iostream>
#include <vector>

//#define NDEBUG // 注释掉这句话，则会开启调试输出代码

using std::cout;
using std::endl;
using std::cin;
using std::vector;

using Iter = vector<int>::iterator;

void print_vec(Iter beg, Iter end)
{
#ifndef NDEBUG
	cout << "vector size: " << end - beg << endl;
#endif

	if (beg != end) {
		cout << *beg << endl;
		print_vec(beg + 1, end);
	}

}

int main()
{
	vector<int> ivec{1, 2, 3, 4, 5};

	print_vec(ivec.begin(), ivec.end());

	return 0;
}
