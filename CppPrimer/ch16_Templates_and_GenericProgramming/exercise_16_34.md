练习16.34：对下面的代码解释每个调用是否合法。如果合法，T的类型是什么？如果不合法，为什么？

```c++
template <class T> int compare(const T&, const T&);
```

(a) compare("hi", "world");

(b) compare("bye", "dad");

---

a非法，因为无法推断出可以绑定到`const T&`的模板实参类型。

b合法，可以推断出这样的模板实参类型：`const char (&)[4]`，它可以绑定到`const T&`。
