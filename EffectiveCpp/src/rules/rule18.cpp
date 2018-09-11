#include "rule18.h"

using namespace rule18;

extern void Rule18()
{
	{
		Date1 d(30, 1, 1995);	// 错了，第一个参数是月份！但仍然通过了编译
		Date1 d2(2, 30, 1995);	// 错了，2月份没有30天
	}

	{
		//Date2 d(30, 3, 1995);	// 错误！类型不对，无法通过编译
		Date2 d(Month::Feb(), Day(30), Year(1995));	// OK ，类型正确
	}
}