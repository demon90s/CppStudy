练习15.38：下面的声明合法吗？如果不合法，请解释原因；如果合法，请指出含义。

```
BinaryQuery a = Query("fiery") & Query("bird");	// 不合法，BinaryQuery是一个抽象类，无法实例化

AndQuery a = Query("fiery") & Query("bird");	// 合法，生成一个AndQuery

OrQuery a = Query("fiery") & Query("bird");		// 不合法，类型不一致
```
