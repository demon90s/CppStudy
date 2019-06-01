> 练习6.53：说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。

(a) int calc(int&, int&);
    int calc(const int&, const int&);

(b) int calc(char*, char*);
    int calc(const char*, const char*);

(c) int calc(char*, char*);
    int calc(char* const, char* const);

---

(a) 合法，使得calc函数可以传递常量对象。

(b) 合法，使得calc函数可以传递指向常量的指针。

(c) 非法，重复定义，顶层const指针和普通指针作为形参没有本质区别。
