/*
 * 练习2.35：判断下列定义推断出的类型是什么，然后编写程序进行验证。
 *
 * const int i = 42;
 * auto j = i; const auto &k = i; auto *p = &i;
 * const auto j2 = i, &k2 = i;
 */

/*
 * j：int
 * k：const int&，绑定到i
 * p：const int*，指向i
 * j2：const int
 * k2：const int&，绑定到i
 */

#include <iostream>

int main()
{
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;

	j = 80;
	std::cout << "j: " << j << "\t" << "i: " << i << std::endl;

	std::cout << "addr of j: " << &j << "\t" << "addr of i: " << &i << std::endl;
	
	// 下面编译报错
	//k = 100;
	//*p = 100;
	//k2 = 100;

	return 0;
}
