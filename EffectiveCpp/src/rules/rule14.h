// 条款14：在资源管理类中小心 copying 行为
#ifndef __RULE14_H__
#define __RULE14_H__

#include "rule06.h"
#include <iostream>
#include <memory>

extern void Rule14();

namespace rule14
{
	class Mutex
	{
		friend void lock(Mutex*);
		friend void unlock(Mutex*);

	public:
		bool IsLocked() const { return is_locked; }

	private:
		bool is_locked = false;
	};

	inline void lock(Mutex *pm) { 
		/* if (locked) wait */pm->is_locked = true;
		std::cout << __FUNCTION__ << std::endl; 
	}
	inline void unlock(Mutex *pm) {
		pm->is_locked = false;
		std::cout << __FUNCTION__ << std::endl;
	}

	// 为了确保解锁，需要建立一个RAII class管理
	class Lock : private Uncopyable // RAII 对象被复制也许并不合理，因此拒绝
	{
	public:
		explicit Lock(Mutex *pm) : mutexPtr(pm) { lock(pm); }
		~Lock() { unlock(mutexPtr); }

	private:
		Mutex *mutexPtr;
	};

	// 使用 shared_ptr 的删除器管理引用计数类型的资源
	class Lock2
	{
	public:
		explicit Lock2(Mutex *pm) : mutexPtr(pm, unlock) { lock(pm); }

	private:
		std::shared_ptr<Mutex> mutexPtr;
	};
}

#endif // __RULE14_H__