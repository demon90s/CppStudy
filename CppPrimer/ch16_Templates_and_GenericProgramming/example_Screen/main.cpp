// example: 窗口类的设计与实现(练习16.14, 16.15, p592)

#include <iostream>
#include "Screen.h"

using std::cout;
using std::cin;
using std::endl;

void func1()
{
	Screen<5, 3> screen('A');

	screen.set('#').display(cout);

	cout << endl;
}

void func2()
{
	Screen<3, 5> screen('0');
	cout << screen;

	cout << "enter some words: ";

	cin >> screen;
	cout << screen;
}

int main()
{
	//func1();
	func2();

	return 0;
}
