#ifndef RAND_TOOL_H
#define RAND_TOOL_H

#include <random>

namespace utility
{

extern void Test_RandFuncs();

// 获取一个范围内[min, max]的随机值
extern unsigned int RandNum(unsigned int min, unsigned int max);

}

#endif // RAND_TOOL_H
