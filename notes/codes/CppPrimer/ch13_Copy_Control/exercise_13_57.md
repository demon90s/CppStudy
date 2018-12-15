练习13.57：如果sorted定义如下，会发生什么：

```
Foo Foo::sorted() const & { return Foo(*this).sorted(); }
```

---

work fine, 由于'Foo(*this)'得到一个临时对象，它是一个右值，因此接下来会调用右值引用版本的sorted。
