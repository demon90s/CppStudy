练习16.59：假定s是一个string，解释调用svec.emplace_back(s)会发生什么。

---

construct调用中的模式会扩展出：

std::forward<string&>(s) -> string& s

从而会调用：alloc.construct(first_free++, s);
