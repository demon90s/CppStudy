// 练习16.3：对两个Sales_data对象调用你的compare函数，观察编译器在实例化
// 过程中如何处理错误。

// 提示：error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)

#include <iostream>

using namespace std;

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}

class Sales_data
{
};

int main()
{
	/*
	Sales_data sd1, sd2;
	compare(sd1, sd2);
	*/

	return 0;
}
