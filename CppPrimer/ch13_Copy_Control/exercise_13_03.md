练习13.3：当我们拷贝一个StrBlob时，会发生什么？拷贝一个StrBlobPtr呢？

---

- 拷贝StrBlob，会拷贝shared_ptr，从而使其引用计数递增。

- 拷贝StrBlobPtr，不会增加其引用计数
