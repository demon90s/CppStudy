// 条款01：视C++为一个语言联邦

#include <vector>
#include <iostream>

struct Foo
{
	Foo(int _i) : i(_i) {}
	int i;
};

void Rule01()
{
	// 对于内置类型，pass-by-value高效
	{
		std::vector<int> ivec{1, 2, 3, 4, 5};
		for (auto i : ivec)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
	

	// 对于用户自定义的类型，往往pass-by-reference-to-const更好
	{
		std::vector<Foo> fvec{1, 2, 3, 4, 5};
		for (const auto &f : fvec)
		{
			std::cout << f.i << " ";
		}
		std::cout << std::endl;
	}

	// 对于迭代器，适用pass-by-value
	{
		std::vector<Foo> fvec{1, 2, 3, 4, 5};
		for (auto it = fvec.cbegin(); it != fvec.cend(); ++it)
		{
			std::cout << it->i << " ";
		}
		std::cout << std::endl;
	}
}