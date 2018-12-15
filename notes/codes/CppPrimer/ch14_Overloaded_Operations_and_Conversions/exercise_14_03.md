练习14.3：string和vector都定义了重载的==以比较各自的对象，假设svec1和svec2是存放string的vector，确定在下面的表达式中分别使用了哪个版本的==？

---

(a) "cobble" == "stone"

使用了内置类型`const char*`的比较操作，比较的是两个字符串的地址。

(b) svec1[0] == svec2[0]

使用的是string的比较操作。

(c) svec1 = svec2

使用的是vector<string>的比较操作。

(d) svec1[0] == "stone"

比较的是string，stone会转换成string类型。
