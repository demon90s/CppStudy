练习18.4：查看图18.1（第693页）所示的继承体系，说明下面的try块有何错误并修改它。

```c++
try {
	// 使用C++标准库
} catch(exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```

---

在这些异常类型中，exception是继承链最顶层的类型，所以它可以匹配所有的异常类型，它会首先被捕获，后续的异常类型就没有机会匹配了。因此我们应该把继承链最底端的类放在前面，而最顶端的类放在后面。

改成下面这样：

```c++
try {
	// 使用C++标准库
} catch(overflow_error eobj) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (exception) { /* ... */ }
```
