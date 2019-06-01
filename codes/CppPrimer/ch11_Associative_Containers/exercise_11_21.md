练习11.21：假定word_count是一个string到size_t的map，word是一个string到size_t的map，word是一个string，解释下面循环的作用：

```
while (cin >> word)
	++word_count.insert({word, 0}).first->second;
```

---

统计word出现的数量信息，存放到word_count里。
