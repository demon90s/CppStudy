练习11.29：如果给定的关键字不在容器中，upper_bound, lower_bound和equal_range分别会返回什么？

---

upper_bound和lower_bound返回相同的迭代器——指向一个不影响排序的关键字插入位置。

equal_range中的两个迭代器都指向可以插入的位置。
