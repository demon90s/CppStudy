> 练习6.52：已知有如下声明：

```
void mainip(int, int);
double dobj;
```

请指出下列调用中每个类型转换的等级（参见6,6,1节，第219页）。

(a) mainip('a', 'z'); (b) mainip(55.4, dobj);

---

(a) 第3个等级，通过类型提升实现的匹配（char --> int）。

(b) 第4个等级，通过算数类型转换实现的匹配（double --> int）。
