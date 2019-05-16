#include <array>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>

/*
 * C++ 标准库保证 array<> 的所有元素一定位于连续且相邻的内存内。
 * 这意味着：无论何处，只要你可以使用寻常的 C-style array ，就可以使用 array<>
 * 
 * 使用 data() 成员函数可以获取到第一个元素的地址，这也是与 C-style array 沟通的接口。
 */
void test_carray_stdarray()
{
	std::array<char, 41> a;		// create static array of 41 chars

	//strcpy(&a[0], "hello, world");	// copy a C-string into the array
	strcpy(a.data(), "hello, world");

	//printf("%s\n", &a[0]);		// print contents of the array as C-string
	printf("%s\n", a.data());
}

// array 的使用案例
void test()
{
	std::ostream_iterator<int> output_it(std::cout, " ");

	// create array with 10 ints
	std::array<int, 10> a = {11, 22, 33, 44};

	std::copy(a.begin(), a.end(), output_it);
	std::cout << std::endl;

	// modify last two elements
	a.back() = 99999;
	a[a.size() - 2] = 42;
	std::copy(a.begin(), a.end(), output_it);
	std::cout << std::endl;

	// process sum of all elements
	std::cout << "sum: "
		  << std::accumulate(a.begin(), a.end(), 0)
		  << std::endl;

	// negate all elements
	std::transform(a.begin(), a.end(), a.begin(), std::negate<int>());
	std::copy(a.begin(), a.end(), output_it);
	std::cout << std::endl;
}

int main()
{
	//test_carray_stdarray();
	
	test();

	return 0;
}
