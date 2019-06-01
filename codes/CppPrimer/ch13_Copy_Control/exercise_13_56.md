练习13.56：如果sorted定义如下，会发生什么：

```
Foo Foo::sorted() const & {
	Foo ret(*this);
	return ret.sorted();
}
```

---

由于ret是一个左值，那么将会出现递归调用（无限递归）。
