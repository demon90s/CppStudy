练习12.3：StrBlob需要const版本的push_back和pop_back吗？如果需要，添加进去。否则，解释为什么不需要。

---

不需要，因为push_back和pop_back都要修改本对象的数据成员，因此不能传入const版本的this指针。
