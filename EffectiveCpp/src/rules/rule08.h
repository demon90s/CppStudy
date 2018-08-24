// 条款08：别让异常逃离析构函数
#ifndef __RULE08_H__
#define __RULE08_H__

#include <stdexcept>
#include <iostream>

extern void Rule08();

#pragma warning(disable:4297) // ignore warning: function assumed not to throw an exception ...

class Widget
{
public:
	~Widget() { throw std::runtime_error("exception occured on destructor"); }
};

#pragma warning(default:4297)

class DBConnection
{
public:
	static DBConnection create()	// 这个函数返回DBConnection对象
	{
		static DBConnection db;
		return db;
	}

	// 关闭联机：失败则抛出异常
	void close()
	{
		int is_succ = false;
		if (!is_succ)
		{
			throw std::runtime_error("close failed");
		}
	}
};

class DBConn
{
public:
	DBConn(const DBConnection& _db) : db(_db), closed(false) {}
	~DBConn()			// 确保数据库连接总是会被关闭
	{
		// 如果close抛出异常，捕获并记录
		try { db.close(); }
		catch (std::runtime_error e) {
			std::cout << e.what() << std::endl;
		}
	}

	// 供客户使用的新函数
	void close()
	{
		db.close();
		closed = true;
	}

private:
	DBConnection db;
	bool closed;
};

#endif //__RULE08_H__