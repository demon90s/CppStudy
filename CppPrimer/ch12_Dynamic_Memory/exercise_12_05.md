练习12.5：我们未编写接受一个initializer_list explicit（参见7.5.4节，第264页）参数的构造函数。讨论这个设计策略的优点和缺点。

---

My: 优点是可以直接使用花括号列表来隐式转换成StrBlob（隐式转换机制）。

Pros：

- The compiler will not use this constructor in an automatic conversion.

- We can realize clearly which class we have used.

Cons:

- We always uses the constructor to construct a temporary StrBlob object.

- cannot use the copy form of initialization with an explicit constructor. not easy to use.

参见：https://github.com/pezy/CppPrimer/tree/master/ch12
