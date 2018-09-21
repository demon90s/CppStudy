#ifndef __RULE23_H__
#define __RULE23_H__

#include <cstring>

extern void Rule23();

namespace rule23
{
	class WebBrowser {
	public:
		void clearCache()
		{
			memset(cache, 0, sizeof(cache));
		}

		void clearHistory()
		{
			memset(history, 0, sizeof(history));
		}

		void removeCookies()
		{
			memset(cookies, 0, sizeof(cookies));
		}

		// 一个执行所有清理工作的方式
		// 但这种方式的封装性低：越多函数可访问封装数据，封装性就越低
		void clearEverthing()
		{
			this->clearCache();
			this->clearHistory();
			this->removeCookies();
		}

	private:
		char cache[1024];
		char history[1024];
		char cookies[1024];
	};

	// 另一种执行所有清理工作的方式
	inline void clearBrowser(WebBrowser &wb)
	{
		wb.clearCache();
		wb.clearHistory();
		wb.removeCookies();
	}
}

#endif // __RULE23_H__