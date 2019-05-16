/*
	UnaryProc
	for_each(InputIterator beg, InputIterator end, UnaryProc op)

	对区间 [beg, end) 中的每一个元素调用 op(elem)
	返回 op 的一个拷贝。
 */

#include <algorithm>
#include <iostream>

void Test1()
{
	// 打印容器中每个元素
	std::vector<int> vec {1, 2, 3, 4, 5};

	for_each(vec.begin(), vec.end(), [](int elem) { 
		std::cout << elem << " "; 
	});
	std::cout << std::endl;
}

// 可调用对象，可获取平均值
class MeanValue {
private:
	long num;	// number of elements
	long sum;	// sum of all elements values
public:
	MeanValue() : num(0), sum(0) {}

	// function call
	void operator() (int elem) {
		num++;
		sum += elem;
	}

	// return mean value (implicit type conversion)
	operator double() {
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

void Test2()
{
	std::vector<int> v {1, 2, 3, 4, 5};

	double mv = for_each(v.begin(), v.end(), MeanValue());

	std::cout << "mean value: " << mv << std::endl;
}

int main()
{
	//Test1();
	Test2();

	return 0;
}
