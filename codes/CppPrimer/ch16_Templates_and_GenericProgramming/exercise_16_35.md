练习16.35：下面调用中哪些是错误的（如果有的话）？如果调用合法，T的类型是什么？如果调用不合法，问题何在？

```c++
template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);

double d; float f; char c;
```
(a) calc(c, 'c');

(b) calc(d, f);

(c) fcn(c, 'c');

(d) fcn(d, f);

---

(a) 合法，T的类型是char。

(b) 合法，T的类型是double。

(c) 合法，T的类型是char。

(d) 不合法，函数实参类型不一致，无法推断出模板实参。
