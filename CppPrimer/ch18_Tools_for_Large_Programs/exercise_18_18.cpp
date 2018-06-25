// 练习18.18：已知有下面的swap的典型定义（参加13.3节，第457页），当mem1是
// 一个string时程序使用swap的哪个版本？如果mem1是int呢？说明在这两种情况下
// 名字查找的过程。

// 查找过程：在std命名空间中查找，找到。

#include <iostream>
#include <string>

struct Boo
{
	std::string mem1;	// 使用：void std::swap(std::string&, std::string&);
};

struct Goo
{
	int mem1 = 0;		// 使用：void std::swap(int&, int&);
};

template<typename T>
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
}

int main()
{
	{
		Boo v1, v2;
		swap(v1, v2);
	}

	{
		Goo v1, v2;
		swap(v1, v2);
	}

	return 0;
}
