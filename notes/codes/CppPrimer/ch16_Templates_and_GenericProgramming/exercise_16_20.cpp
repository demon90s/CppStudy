// 练习16.20：重写上一题的函数，使用begin和end返回的迭代器来控制循环。

// 练习16.19：编写函数，接受一个容器的引用，打印容器中的元素。使用容器的size_type
// 和size成员来控制打印元素的循环。

#include <iostream>
#include <vector>
#include <set>

template<typename Container>
void print_container(const Container &container)
{
	for (auto it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4};
	print_container(vec);

	std::set<int> set1 = {1, 2, 3, 4};
	print_container(vec);

	return 0;
}
