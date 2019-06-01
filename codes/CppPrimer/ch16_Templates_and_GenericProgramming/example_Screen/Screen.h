#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

using pos = std::string::size_type;

template<pos heigth, pos width>
class Screen;

template<pos height, pos width>
std::istream& operator>>(std::istream&, Screen<height, width>&);

template<pos height, pos width>
std::ostream& operator<<(std::ostream&, const Screen<height, width>&);

template<pos height, pos width>
class Screen
{
	friend std::istream& operator>><height, width>(std::istream&, Screen<height, width>&);

public:
	Screen() = default;	// 因为Screen有另一个构造函数，所以本函数是必须的
	// cursor被其类内初始值初始化为0
	Screen(char c) : contents(height * width, c) {}

	pos size() const;
	
	char get() const { return contents[cursor]; }	// 读取光标处的字符，隐式内联
	char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);						// 可以在之后设置为内联

	Screen &set(char c);
	Screen &set(pos row, pos col, char c);

	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this;  }

private:
	// 该函数负责显示Screen的内容
	void do_display(std::ostream &os) const { os << contents; }

	pos cursor = 0;
	std::string contents;

	mutable size_t access_get_ctr;	// 即使在一个const对象内也能被修改
};

template<pos height, pos width>
inline
pos Screen<height, width>::size() const
{
	return height * width;
}

template<pos height, pos width>
inline
Screen<height, width>& Screen<height, width>::move(pos r, pos c) 
{
	pos row = r * width;	// 计算行的位置
	cursor = row + c;		// 在行内将光标移动到指定的列

	++access_get_ctr;
	return *this;
}

template<pos height, pos width>
inline char Screen<height, width>::get(pos r, pos c) const
{
	pos row = r * width;	// 计算行的位置
	return contents[row + c]; // 返回给定列的字符
}

template<pos height, pos width>
inline
Screen<height, width>& Screen<height, width>::set(char c)
{
	contents[cursor] = c;
	return *this;
}

template<pos height, pos width>
inline
Screen<height, width>& Screen<height, width>::set(pos row, pos col, char c)
{
	contents[row * width + col] = c;
	return *this;
}

template<pos height, pos width>
std::istream& operator>>(std::istream &is, Screen<height, width> &screen)
{
	std::string str;
	if (getline(is, str)) {
		for (auto c : str)
		{
			screen.set(c);
			screen.cursor = (screen.cursor + 1) % screen.contents.size();
		}
	}
	return is;
}

template<pos height, pos width>
std::ostream& operator<<(std::ostream &os, const Screen<height, width> &screen)
{
	for (size_t l = 0; l < height; ++l) {
		for (size_t r = 0; r < width; ++r) {
			os << screen.get(l, r);
		}
		std::cout << "\n";
	}
	return os;
}

#endif
