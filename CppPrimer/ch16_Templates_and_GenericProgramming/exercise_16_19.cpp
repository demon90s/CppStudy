// 练习16.19：编写函数，接受一个容器的引用，打印容器中的元素。使用容器的size_type
// 和size成员来控制打印元素的循环。

#include <iostream>
#include <vector>

template<typename Container>
void print_container(const Container &container)
{
	for (typename Container::size_type i = 0; i < container.size(); ++i) {
		std::cout << container[i];
		if (i != container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = {1, 2, 3, 4};
	print_container(vec);

	return 0;
}
