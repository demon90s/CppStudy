练习16.17：声明为typename的类型参数和声明为class的类型参数有什么不同（如果有的话？）什么时候必须使用typename？

---

如果是作为模板参数，二者没有区别。

如果是为了使用模板参数的类型成员，就必须使用typename，告诉编译器该名字是一个类型：

```c++
return typename T::value_type();
```
