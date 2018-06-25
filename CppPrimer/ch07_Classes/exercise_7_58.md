> 练习7.58：下面的静态数据成员的声明和定义有错误吗？请解释原因。

```
// example.h
class Example {
public:
	static double rate = 6.5;

	static const int vecSize = 20;
	static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```

---

错误如下：

```
static double rate = 6.5;
              ^
              普通的静态成员不应该在类的内部初始化

static vector<double> vec(vecSize);
                          ^
                          应该在类的外部对vec初始化
```

修改：

```
class Example {
public:
	static constexpr double rate = 6.5;

	static const int vecSize = 20;
	static vector<double> vec;
};
// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(vecSize);
```
