#include "Application.h"
#include <iostream>

void func()
{
	int ret = compare(5, 10);			// 已经实例化声明, 因此不会被实例化, 必须在程序的其他地方显式实例化
	std::cout << ret << std::endl;
}
