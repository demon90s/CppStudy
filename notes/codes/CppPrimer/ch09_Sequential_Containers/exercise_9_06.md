> 练习9.6：下面程序有何错误？你应该如何修改它？

```
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst2.end();

while (iter1 < iter2) /* ... */
             ^
			 list的迭代器不支持<运算符，需要使用通用的!=运算符
```
