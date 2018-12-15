// example: 类成员指针（p739）

#include <string>
#include <iostream>

class Screen
{
public:
	typedef std::string::size_type pos;

	Screen(const std::string &_contents) : contents(_contents), cursor(0), height(4), weight(6) {}

	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd) const;

	// data是一个静态成员，返回一个成员指针
	static const std::string Screen::*data()
	{ return &Screen::contents; }

private:
	std::string contents;
	pos cursor;
	pos height, weight;
};

int main()
{
	// 数据成员指针
	{
		// pdata可以指向一个Screen对象的string成员
		// 使用类的成员初始化
		const std::string Screen::*pdata = Screen::data();

		// 使用
		Screen myscreen("hello"), *pScreen = &myscreen;
		std::cout << myscreen.*pdata << std::endl;
		std::cout << pScreen->*pdata << std::endl;
	}

	return 0;
}
