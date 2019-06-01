/*
 * 练习7.24：给你的Screen类添加三个构造函数：一个默认构造函数；另一个构造函数
 * 接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受
 * 宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容。
 */

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

class Screen
{
public:
	//typedef std::string::size_type pos;
	using pos = std::string::size_type;
	Screen() = default;	// 因为Screen有另一个构造函数，所以本函数是必须的
	// cursor被其类内初始值初始化为0
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
	
	char get() const { return contents[cursor]; }	// 读取光标处的字符，隐式内联
	inline char get(pos ht, pos wd) const;			// 显示内联
	Screen &move(pos r, pos c);						// 可以在之后设置为内联

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_get_ctr;	// 即使在一个const对象内也能被修改
};

inline
Screen& Screen::move(pos r, pos c) 
{
	pos row = r * width;	// 计算行的位置
	cursor = row + c;		// 在行内将光标移动到指定的列

	++access_get_ctr;
	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;	// 计算行的位置
	return contents[row + c]; // 返回给定列的字符
}

int main()
{
	Screen screen(24, 80);
	std::cout << screen.get() << std::endl;

	return 0;
}

#endif
