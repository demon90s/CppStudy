> 练习6.18：为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。

 (a) 名为compare的函数，返回布尔值，两个参数都是matrix类的引用。
 (b) 名为change_val的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。

---

(a)

```
bool compare(const matrix &rh, const matrix &lh); // 判断两个对象的大小
```

(b)

```
vector<int>::iterator change_val(int i, vector<int>::iterator it);	// 把it绑定到的元素的值替换为i，返回替换后元素位置的迭代器（也许吧？）
```
