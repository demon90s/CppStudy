#include "rule20.h"
#include <cstdio>
#include "../pitime.h"

using namespace rule20;

void Rule20()
{
	// 用传引用的方式避免拷贝，从而提高效率
	{
		Student s;

		auto beg_time = PITime();
		for (int i = 0; i < 100000; ++i)
		{
			validateStudent(s);
		}
		auto end_time = PITime();
		printf("pass-by-value cost time: %lu ms\n", end_time - beg_time);

		beg_time = PITime();
		for (int i = 0; i < 100000; ++i)
		{
			validateStudent2(s);
		}
		end_time = PITime();
		printf("pass-by-reference-to-const cost time: %lu ms\n", end_time - beg_time);
	}

	// 用传引用的方式避免 slicing 问题
	{
		WindowWithScrollBars wsb("WindowWithScrollBars");
		printNameAndDisplay(wsb);

		printNameAndDisplay2(wsb);
	}
}
