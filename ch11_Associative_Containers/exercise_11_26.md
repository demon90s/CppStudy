练习11.26：可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返回的类型。

---

只要这个类型可以作为map的关键字，就可以将其作为下标。

下标运算符返回的类型是map中对应键的值(value_type对象)。

```
map<string, size_t> word_cnt;

string key = "hello";
size_t cnt = word_cnt[key];
```
