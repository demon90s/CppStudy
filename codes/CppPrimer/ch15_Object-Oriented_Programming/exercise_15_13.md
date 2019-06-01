练习15.13：给定下面的类，解释每个print函数的机理：

```
class base
{
public:
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};

class derived : base
{
public:
	void print(ostream &os) { print(os); os << " " << i; }
private:
	int i;
};
```

上述代码中存在问题吗？如果有，你该如何修改它？

---

derived的print函数有问题，由于调用了自身的print，会造成递归调用。应该调用基类的：base::print。
