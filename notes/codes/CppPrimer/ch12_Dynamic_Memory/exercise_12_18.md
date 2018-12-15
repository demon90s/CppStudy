练习12.18：shared_ptr为什么没有release成员？

---

release让unique_ptr放弃对动态内存的管理，但shared_ptr不需要放弃，因为还有其他的shared_ptr共享着动态内存。
