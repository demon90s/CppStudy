练习12.25：给定下面的new表达式，你应该如何释放pa？

```
int *pa = new int[10];
```

---

```
delete []pa;
```
