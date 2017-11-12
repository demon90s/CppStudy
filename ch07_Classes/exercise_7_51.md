> 练习7.51：vector将其单参数的构造函数定义成explicit的，而string则不是，
你觉得原因何在？

---

如果vector可以有隐式转换，举个例子，这样的初始化语句是合法的：

```
vector<int> ivec = 10;
```

然而这样做显得不自然。

但string却显得自然许多：

```
string s = "Hello";
```
