#include "rule14.h"

using namespace rule14;

extern void Rule14()
{
	Mutex m;
	{
		Lock m1(&m);

		// 执行 critical section 内的操作
		// 在区块最末尾，自动解除互斥器锁定
	}

	{
		Lock2 m2(&m);

		// 区块最末尾，自动解除锁定
	}
}