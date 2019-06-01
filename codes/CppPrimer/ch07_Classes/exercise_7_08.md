> 练习7.8：为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用？

---

因为read需要改变传入的Sales_data对象，print无需改变，为了使得print也能够处理常量对象，必须将其参数定义成常量引用。
