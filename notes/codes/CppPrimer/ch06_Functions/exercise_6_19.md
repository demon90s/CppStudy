练习6.19：假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。

```
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

(a) calc(23.4, 55.1);		// 不合法，形参和实参数量不匹配

(b) count("abcda", 'a');	// 合法

(c) calc(66);				// 合法

(d) sum(vec.begin(), vec.end(), 3.8);	// 合法
