尾置返回类型（trailing return type）在参数列表后面指定的返回类型。

如：

```
// func接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组
auto func(int i) -> int(*)[10];
```

见p206。
