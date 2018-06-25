// 条款02：尽量以const, enum, inline替换#define

#ifndef __RULE02_H__
#define __RULE02_H__

#include <string>

#define ASPECT_RATIO 1.653	// 宏定义不会计入记号表（symbol table）

const double AspectRatio = 1.653;	// 使用常量替换上述宏

const char* const authorName = "Scott Meyers"; // 定义常量char*-based字符串

const std::string authorName2("Scott Meyers"); // 定义常量字符串更合宜的办法

// class的专属常量
class GamePlayer
{
private:
	static const int NumTurns = 5;	// 常量声明式
	int scores[NumTurns];			// 使用该常量
};

class GamePlayer2
{
private:
	enum { NumTurns = 5 };			// "the enum hack" 令NumTurns成为5的一个记号名称
	int scores[NumTurns];			// 使用该常量
};

// 使用inline template函数代替形似宏
extern void rule02_f(int i);
#define CALL_WITH_MAX(a, b) rule02_f((a) > (b) ? (a) : (b))

template<typename T>
inline void CallWithMax(const T &a, const T &b)
{
	rule02_f(a > b ? a : b);
}

extern void Rule02();

#endif // __RULE02_H__