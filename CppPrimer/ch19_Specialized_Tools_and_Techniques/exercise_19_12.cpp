// 练习19.12：定义一个成员指针，令其可以指向Screen类的cursor成员。
// 通过该指针获得Scene::cursor的值。

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

	static const pos Screen::*pcursor()
	{ return &Screen::cursor; }

private:
	std::string contents;
	pos cursor;
	pos height, weight;
};

int main()
{
	// 数据成员指针
	{
		auto pcursor = Screen::pcursor();

		// 使用
		Screen myscreen("hello");
		std::cout << myscreen.*pcursor << std::endl;
	}

	return 0;
}
