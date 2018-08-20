// 条款13：以对象管理资源
#ifndef __RULE13_H__
#define __RULE13_H__

#include <iostream>
#include <memory>

extern void Rule13();

namespace rule13
{
	// “投资类型”继承体系中的root class
	class Investment
	{
	public:
		Investment() { std::cout << "Investment()" << std::endl; }
		~Investment() { std::cout << "~Investment()" << std::endl; }
	};

	// 通过工厂函数分配动态对象
	inline Investment* createInvestment()
	{
		return new Investment();
	}

	inline Investment* createInvestmentList(int n)
	{
		return new Investment[n];
	}

	inline void bug()
	{
		Investment *pInv = createInvestment();
		return; // 由于某种原因不小心return了，则造成了内存泄漏
		delete pInv;
	}

	inline void use_auto_ptr()
	{
		// auto_ptr的析构函数会对对象执行delete
		std::auto_ptr<Investment> pInv(createInvestment());

		std::auto_ptr<Investment> pInv2(pInv);	// 现在pInv2指向对象，pInv为nullptr

		pInv = pInv2;							// 现在pInv指向对象，pInv2为nullptr
	}

	inline void use_shared_ptr()
	{
		// shared_ptr可以令多个指针指向同一个对象
		std::shared_ptr<Investment> pInv(createInvestment());

		std::shared_ptr<Investment> pInv2(pInv);	// pInv和pInv2指向同一个对象
	}

	inline void use_unique_ptr()
	{
		// unique_ptr可以用于分配动态数组
		std::unique_ptr<Investment[]> pInv(createInvestmentList(3));
	}
}

#endif // __RULE13_H__