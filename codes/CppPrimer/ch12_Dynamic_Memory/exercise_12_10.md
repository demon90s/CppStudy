练习12.10：下面的代码调用了第413页中定义的process函数，解释此调用是否正确。如果不正确，应如何修改？

```
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

---

正确。p是一个智能指针，其指向的动态内存会被正确释放。
