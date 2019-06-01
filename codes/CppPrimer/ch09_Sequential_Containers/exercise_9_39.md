> 练习9.39：解释下面程序片段做了什么？

```
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size()/2);
```

---

```
vector<string> svec;		// 定义一个空的vector，存放string对象
svec.reserve(1024);			// 将vector的capacity设置为1024，可能更大
string word;				// 定义一个string变量
while (cin >> word)			// 循环读取字符串，然后将其存入容器，如果容器的capacity不足了，
	svec.push_back(word);	// 会扩张capacity
svec.resize(svec.size() + svec.size()/2);	// 增加当前容器元素数量一般的元素，此时capacity可能
											// 不会增长，也可能会增长
```
