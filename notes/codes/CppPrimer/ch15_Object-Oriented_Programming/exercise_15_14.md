练习15.14：给定上一题中的类以及下面这些对象，说明在运行时调用哪个函数？

```
base bobj;
base *bp1 = &bobj;
base &br1 = bobj;

derived dboj;
base *bp2 = &dobj;
base &br2 = dobj;
```

---

(a) bobj.print(); // base::print

(b) dboj.print(); // derived::print

(c) bp1->name(); // base::name

(d) bp2->name(); // base::name

(e) br1.print(); // base::print

(f) br2.print(); // derived::print
