> 练习10.26：解释三种插入迭代器的不同之处。

---

back_inserter调用push_back把元素插入到容器尾部。

front_inserter调用push_front把元素插入到容器首部。

inserter调用insert将元素插入到其绑定到的迭代器之前的位置。
