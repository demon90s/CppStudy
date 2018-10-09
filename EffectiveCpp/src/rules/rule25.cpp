#include "rule25.h"
#include "../pitime.h"

using namespace rule25;

void Rule25()
{
	// 交换若干次，查看效果
	Widget w1, w2;

	unsigned long beg_time = PITime();
	for (int i = 0; i < 10000; i++)
	{
		/*
		 若采用默认的 swap 操作，将承受赋值的代价
		 采用自定义的 swap 操作，直接交换指针，而不拷贝具体的内容， HUGE SPEED 提升
		*/
		//std::swap(w1, w2);

		using namespace std;
		swap(w1, w2);	// 尽管有 using 声明式，但仍会调用正确的版本
	}
	unsigned long end_time = PITime();

	printf("use time: %lu ms\n", end_time - beg_time);
}
