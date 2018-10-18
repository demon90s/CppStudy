// 条款20：宁以 pass-by-reference-to-const 替换 pass-by-value
#ifndef __RULE20_H__
#define __RULE20_H__

#include <string>
#include <iostream>

extern void Rule20();

namespace rule20
{
	// 下面的类型用于测试拷贝，应当使用 pass-by-reference-to-const
	class Person
	{
	public:
		Person() {}
		virtual ~Person() {}

	private:
		std::string name = "DefaultName";
		std::string address = "DefaultAddr";
	};

	class Student : public Person
	{
	public:
		Student() {}
		~Student() {}

	private:
		std::string schoolName = "DefaultSchoolName";
		std::string schoolAddress = "DefaultSchoolAddr";
	};

	inline bool validateStudent(Student s) { return false; } // 函数以 by-value	方式传递参数
	inline bool validateStudent2(const Student& s) { return false; } // pass=by-reference-to-const

	class Window
	{
	public:
		Window(const std::string &name) : name_(name) {}
		std::string name() const { return name_; }
		virtual void display() const { std::cout << "Window display" << std::endl; }
	private:
		std::string name_;
	};

	class WindowWithScrollBars : public Window
	{
	public:
		WindowWithScrollBars(const std::string &name) : Window(name) {}
		virtual void display() const { std::cout << "WindowWithScrollBars display" << std::endl; }
	private:
		int type = 1;
	};

	// 不正确，参数可能被切割（传入实参类型是 WindowWithScrollBars ）
	inline void printNameAndDisplay(Window w)
	{
		std::cout << w.name() << std::endl;
		w.display();
	}

	// 参数不会被切割
	inline void printNameAndDisplay2(const Window& w)
	{
		std::cout << w.name() << std::endl;
		w.display();
	}
}

#endif // __RULE20_H__