// test: 测试不完全类型（p250）

// 不完全类型（incomplete type）：已经声明但是尚未定义的类型。不完全类型不能用于
// 定义变量或者类的成员，但是用不完全类型定义指针或者引用是合法的。

// My Note: 如下案例所示，定义一个空的包含不完全类型的容器也是合法的。

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

class Child;	// 前向声明一个不完全类型
class Parent
{
	vector<Child> child_vec;
};

class Child
{
	int id;
};

int main()
{
	return 0;
}
