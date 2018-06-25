> 练习7.33：如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了问题，请尝试修改它。

```c++
pos Screen::size() const
{
	return height * width;
}
```

---

无法通过编译，因为在外部作用域内找不到pos这个名字。g++提示：error: ‘pos’ does not name a type

改成：

```c++
Screen::pos Screen::size() const
{
	return height * width;
}
```
