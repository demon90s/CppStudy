> 练习10.7：下面程序是否有错误？如果有，请改正。

(a)
```
vector<int> vec; list<int> lst; int i;
while (cin >> i)
	lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
                               ^
							   错误，vec为空，应该改写为back_inserter(vec)
```

(b)
```
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);
       ^
	   错误，vec为空，应该改写为back_inserter(vec)
```
