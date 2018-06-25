// 条款2：尽量以const, enum, inline替换#define

#ifndef __RULE02_H__
#define __RULE02_H__

#include <string>

#define ASPECT_RATIO 1.653	// 宏定义不会计入记号表（symbol table）

const double AspectRatio = 1.653;	// 使用常量替换上述宏

const char* const authorName = "Scott Meyers"; // 定义常量char*-based字符串

const std::string authorName2("Scott Meyers"); // 定义常量字符串更合宜的办法

#endif // __RULE02_H__