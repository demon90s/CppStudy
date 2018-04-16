练习15.29：再运行一次你的程序，这次传入Quote对象的shared_ptr。如果这次计算出的总额与之前的程序不一致，解释为什么；如果一致，也请说明原因。

---

见[案例](./example_derived_class.cpp)

这次的计算结果不一致。因为上个版本虽然传入的是Bulk_quote，但实际上vector里面插入的仍然是Quote对象；而这个版本，vector中存放的是Quote的智能指针，它可以动态绑定到Bulk_quote类型的对象上面。
