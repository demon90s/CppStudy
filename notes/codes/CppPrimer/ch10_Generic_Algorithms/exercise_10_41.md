> 练习10.41：仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：

```
replace(beg, end, old_val, new_val); // 将序列中的元素为old_val的替换为new_val
replace_if(beg, end, pred, new_val); // 将序列中的元素满足pred条件的替换为new_val
replace_copy(beg, end, dest, old_val, new_val); // 将序列中的old_val替换成new_val，存储到dest所起始的序列中，原序列不变
replace_copy_if(beg, end, dest, pred, new_val); // 将序列中的满足pred条件的元素替换成new_val，存储到dest所起始的序列中，原序列不变
```
