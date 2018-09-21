# 条款23：宁以 non-member, non-friend 替换 member 函数

---

有一些函数，可能用 non-member, non-friend 来实现会更好。

以此为例：

```c++
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
```

如果 clearEverthing 是一个 member 函数，它可能会降低封装性。如果提供一个 non-member 函数，比如：

```c++
// 另一种执行所有清理工作的方式
inline void clearBrowser(WebBrowser &wb)
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}
```

这样的函数允许对 WebBrowser 相关机能有较大的包裹弹性（ packaging flexibility ），而那最终导致较低的编译相依度，增加 WebBrowser 的可延伸性。 

C++中比较自然的做法是让 clearBrowser 成为一个 non-member 函数并且位于 WebBrowser 所在的同一个 namespace 内。

namespace 和 classes 不同，前者可以跨越多个源码文件而后者不能。

!!!tip "请记住"
	宁可拿 non-member non-friend 函数替换 member 函数。这样做可以增加封装性、包裹弹性和机能扩充性。