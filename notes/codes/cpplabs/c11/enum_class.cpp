/*
	也即 scoped enumeration

	如：
	enum class Color : char { red, yellow, blue };

	scoped enumration 有以下优点：
	- 绝不会隐式转换至/自 int
	- 必须使用作用域运算符来在外部使用枚举成员
	- 可以明显定义低层类型，并因此获得一个保证大小（如 char ，默认是 int ）
	- 可以前置声明
 */

#include <iostream>

enum class Color : char {
	red, 
	yellow, 
	blue,

	//bad=1000, // 编译错误
};

void foo(Color c) { std::cout << static_cast<int>(c) << std::endl; }

int main()
{
	//Color color = 2; // 隐式转换, 非法
	Color color = Color::red; // OK

	//int i = color;	// 隐式转换, 非法
	char c = static_cast<char>(color); // OK
	
	//foo(c); // 隐式转换, 非法
	foo(static_cast<Color>(c)); // OK

	foo(static_cast<Color>(1000));	// OK but overflow

	return 0;
}
