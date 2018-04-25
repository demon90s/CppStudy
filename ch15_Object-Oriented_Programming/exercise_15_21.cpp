// 练习15.21：从下面这些一般性抽象概念中任选一个（或者选一个你自己的），将其对应
// 的一组类型组织成一个继承体系：
/*
(a) 图形文件格式（如git、tiff、jpeg、bmp）

(b) 图形基元（如方格、圆、球、圆锥）

(c) C++语言中的类型（如类、函数、成员函数）
 */

#include <iostream>
#include <cstdio>

using namespace std;

enum SHAPE_TYPE
{
	SHAPE_TYPE_INVALID = 0,
	SHAPE_TYPE_SQUARE = 1,
	SHAPE_TYPE_CIRCLE = 2,
};

class Shape
{
public:
	Shape(int type) : m_type(type) {}
	
	virtual void Print() const = 0;

protected:
	int m_type;
};

class Square : public Shape
{
public:
	Square() : Shape(SHAPE_TYPE_SQUARE), m_height(1), m_width(1) {}

	void Print() const override { printf("[Square] height: %g, width: %g\n", m_height, m_width); }

private:
	double m_height;
	double m_width;
};

class Circle : public Shape
{
public:
	Circle() : Shape(SHAPE_TYPE_CIRCLE), m_radius(1) {}
	
	void Print() const override { printf("[Circle] radius: %g", m_radius); }

private:
	double m_radius; 
};

int main()
{
	Square square;
	square.Print();

	Circle circle;
	circle.Print();

	return 0;
}
