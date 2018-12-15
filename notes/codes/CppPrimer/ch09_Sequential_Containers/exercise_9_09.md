> 练习9.9：begin和cbegin两个函数有什么不同？

---

begin返回迭代器类型依赖于容器的类型，如果容器是const的，则迭代器是const_iterator，否则是iterator；cbegin返回的是const_iterator。
