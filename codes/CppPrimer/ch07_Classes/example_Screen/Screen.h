#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen
{
	friend class Window_mgr;

public:
	//typedef std::string::size_type pos;
	using pos = std::string::size_type;
	Screen() = default;	// 因为Screen有另一个构造函数，所以本函数是必须的
	// cursor被其类内初始值初始化为0
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

	pos size() const;
	
	char get() const { return contents[cursor]; }	// 读取光标处的字符，隐式内联
	inline char get(pos ht, pos wd) const;			// 显示内联
	Screen &move(pos r, pos c);						// 可以在之后设置为内联

	Screen &set(char c);
	Screen &set(pos row, pos col, char c);

	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this;  }

private:
	// 该函数负责显示Screen的内容
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	mutable size_t access_get_ctr;	// 即使在一个const对象内也能被修改
};

inline
Screen::pos Screen::size() const
{
	return height * width;
}

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

inline
Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen& Screen::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

#endif
