// example: 成员指针函数表（p743）

#include <iostream>

using namespace std;

class Screen
{
public:
	Screen& home() { cout << __FUNCTION__ << endl; return *this; }
	Screen& forward() { cout << __FUNCTION__ << endl; return *this; }
	Screen& back() { cout << __FUNCTION__ << endl; return *this; }
	Screen& up() { cout << __FUNCTION__ << endl; return *this; }
	Screen& down() { cout << __FUNCTION__ << endl; return *this; }

	// Action是一个指针，可以用任意一个光标移动函数进行赋值
	using Action = Screen& (Screen::*)();

	enum Directions { HOME, FORWARD, BACK, UP, DOWN };
	Screen& move(Directions);

private:
	static Action Menu[];		// 函数表
};

Screen::Action Screen::Menu[] = {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};

Screen& Screen::move(Directions dir)
{
	return (this->*Menu[dir])();
}

int main()
{
	Screen screen;
	screen.move(Screen::HOME).move(Screen::FORWARD).move(Screen::BACK).move(Screen::UP).move(Screen::DOWN);

	return 0;
}
