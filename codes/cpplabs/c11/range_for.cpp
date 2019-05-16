/*
	range-base for 循环
	
	c++11 的一种崭新的 for 循环形式，可以逐一迭代某个给定的区间、数组、集合内的每一个元素。

	一般性语法：
	for (decl : coll) {
		statement
	}

	decl 是 coll 集合中的每个元素的声明，然后针对这些元素，给定的 statement 会被执行。

	这要求 coll 提供成员函数 begin() 和 end()
	如果不满足，那么若支持 std::begin(coll) 和 std::end(coll) 也可。
*/

#include <iostream>
#include <string>

void test1()
{
	for (int i : {1, 2, 3, 4}) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	int arr[] = {5, 6, 7 ,8};
	for (auto i : arr) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

class IntArr {
public:
	explicit IntArr(int cnt) : cnt_(cnt) 
	{ list_ = new int[10]{}; }

	~IntArr()
	{
		delete[] list_;
	}

	IntArr(const IntArr&) = delete;
	IntArr& operator=(const IntArr&) = delete;

	int& operator[](int i)
	{ return list_[i]; }

	int* begin() { return list_; }
	int* end() { return list_ + cnt_; }

private:
	int cnt_;
	int *list_;
};

void test2()
{
	IntArr int_arr(10);

	for (auto &i : int_arr) {
		i = 10;
	}

	for (auto i : int_arr) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}

int main()
{
	test1();
	//test2();
	
	return 0;
}
