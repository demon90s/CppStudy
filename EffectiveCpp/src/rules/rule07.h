// 条款07：为多态基类声明virtual析构函数
#ifndef __RULE07_H__
#define __RULE07_H__

#include <ctime>

extern void Rule07();

class TimeKeeper
{
public:
	TimeKeeper() {}
	//~TimeKeeper() {}		// 这里不应该有 non-virtual 析构函数，如果delete derived class，结果未定义
	virtual ~TimeKeeper() {}// 正确，会销毁整个对象

	virtual time_t GetCurrentTime() { return 0; }
};

class AtomicClock : public TimeKeeper {};			// 原子钟
class WaterClock : public TimeKeeper {};			// 水钟
class WristWatch : public TimeKeeper {};			// 腕表

// 返回一个指针，指向一个TimeKeeper派生类的动态分配对象
inline TimeKeeper* getTimerKeeper()
{
	return new AtomicClock;
}

// 如果class不含virtual函数，令其析构函数为virtual往往是个馊主意
class Point {
public:
	Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
	~Point() {}
	//virtual ~Point() {}	// 馊主意，对象大小增加32bit ~ 64bit，因添加了一个vptr指针

private:
	int x, y;
};

#endif // __RULE07_H__ 