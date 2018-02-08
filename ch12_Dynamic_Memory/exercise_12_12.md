练习12.12：p和q的定义如下，对于接下来的对process的每个调用，如果合法，解释它做了什么，如果不合法，解释错误的原因：

```
auto p = new int();
auto sp = make_shared<int>();
```

(a) process(sp); // 合法，正确拷贝、销毁形参

(b) process(new int()); // 错误，不能隐式初始化一个智能指针

(c) process(p); // 错误，不能隐式初始化一个智能指针

(d) process(shared_ptr<int>(p)); // 编译正确，但使用错误，这个操作会将p指向的内存释放掉，从而将p变成悬空指针。
