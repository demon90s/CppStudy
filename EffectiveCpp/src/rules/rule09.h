#ifndef __RULE09_H__
#define __RULE09_H__

#include <string>
#include <iostream>

extern void Rule09();

namespace bug
{
	// 所有交易的base class
	class Trasaction
	{
	public:
		Trasaction()
		{
			// ...
			logTransaction();	// 错误！没有办法调用派生类重写的函数，C++不允许
		}
		virtual void logTransaction() const = 0;		// 做出一份因类型不同而不同的日志记录（log entry）
	};

	class BuyTransaction : public Trasaction
	{
	public:
		virtual void logTransaction() const { std::cout << "BuyTransaction::logTransaction" << std::endl; }		// Log此型交易
	};

	inline void Trasaction::logTransaction() const { std::cout << "Trasaction::logTransaction" << std::endl; }
}

namespace correct
{
	class Transaction
	{
	public:
		explicit Transaction(const std::string& log_info)
		{
			logTransaction(log_info); // 如今是个non-virtual调用
		}

		void logTransaction(const std::string& log_info) const // 如今是个non-virtual函数
		{
			std::cout << log_info << std::endl;
		}
	};

	class BuyTransaction : public Transaction
	{
	public:
		BuyTransaction() : Transaction(createLogString("Construct")) {} // 将Log信息传递给base class构造函数

	private:
		static std::string createLogString(const char* log) { return std::string("BuyTransaction_") + log; }
	};
}

#endif //__RULE09_H__