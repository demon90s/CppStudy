练习18.24：在第714页，我们使用一个指向Panda对象的Bear指针进行了一系列调用，假设我们使用的是一个指向Panda对象的ZooAnimal指针将发生什么情况，请对这些调用语句逐一进行说明。

---

```c++
ZooAnimal *pz = new Panda("yang_yang");
pz->print();		// 正确：Panda::print()
pz->toes();		// 错误：不属于ZooAnimal接口
pz->cuddle();		// 错误：不属于ZooAnimal接口
pz->highlight();	// 错误：不属于ZooAnimal接口
delete pz;		// 正确：Panda::~Panda
```
