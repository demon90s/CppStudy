> 练习7.37：使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象所有数据成员的值。

```c++
Sales_data first_item(cin);
int main() {
	Sales_data next;
	Sales_data last("9-999-99999-9");
}
```

---

##### Sales_data first_item(cin);

调用：Sales_data(std::istream &is)

数据成员值：依赖于从标准输入读取的数据

##### Sales_data next;

调用：Sales_data(std::string s = "")

数据成员值：

- bookNo：空字符串
- units_sold: 0
- revenue: 0.0

##### Sales_data last("9-999-99999-9");

调用：Sales_data(std::string s = "")

数据成员值：

- bookNo：字符串"9-999-99999-9"
- units_sold: 0
- revenue: 0.0
