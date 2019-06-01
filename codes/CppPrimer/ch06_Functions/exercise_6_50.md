> 练习6.50：已知有第217页对函数f的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？

(a) f(2.56, 42) (b) f(42) (c) f(42, 0) (d) f(2.56, 3.14)

---

(a) 可行函数有：`void f(int, int);`, `void f(double, double = 3.14);`, 不合法，二义性调用。

(b) 可行函数有：`void f(int);`, 最佳匹配是`void f(int);` 。

(c) 可行函数有：`void f(int, int);`, `void f(double, double = 3.14);`, 最佳匹配是`void f(int, int);`。

(d) 可行函数有：`void f(int, int);`, `void f(double, double = 3.14);`, 最佳匹配是`void f(double, double = 3.14);`。
