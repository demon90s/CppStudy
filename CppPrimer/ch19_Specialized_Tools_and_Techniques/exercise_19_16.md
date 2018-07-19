练习19.16：声明一个类型别名，令其作为指向Sales_data的avg_price成员的指针的同义词。

---

using AvgPrice = double (Sales_data::*)() const;
