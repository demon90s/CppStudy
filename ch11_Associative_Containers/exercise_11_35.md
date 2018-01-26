练习11.35：在buildMap中，如果进行如下改写，会有什么效果？

trans_map[key] = value.substr(1);

改为trans_map.insert({key, value.substr(1)})

---

下标版本的，更新最后一次操作的元素。

插入版本的，如果后续插入相同键值的元素，则不会改变原有的元素。
