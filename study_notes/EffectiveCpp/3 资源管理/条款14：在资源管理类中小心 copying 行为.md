# 条款14：在资源管理类中小心 copying 行为

---

有时候资源并非 heap-based ，这时候用 auto_ptr 或者 shared_ptr 管理就不太适合了。这时候，可能需要建立自己的资源管理类。

例如，为了确保绝不会忘记将一个被锁住的 Mutex 解锁，可以建立一个 class 来管理锁。这样的 class 的基本结构由 RAII 守则支配，也就是“资源在构造期间获得，在析构期间释放”。

```c++
// 为了确保解锁，需要建立一个RAII class管理
class Lock : private Uncopyable // RAII 对象被复制并不合理，因此拒绝
{
public:
	explicit Lock(Mutex *pm) : mutexPtr(pm) { lock(pm); }
	~Lock() { unlock(mutexPtr); }

private:
	Mutex *mutexPtr;
};
```

客户对 Lock 的用法符合 RAII 方式：

```c++
Mutex m;
{
	Lock m1(&m);

	// 执行 critical section 内的操作
	// 在区块最末尾，自动解除互斥器锁定
}
```

## 如果 RAII 对象复制

“当一个 RAII 对象被复制，会发生什么事？”大多数时候你会选择以下可能：

- **禁止复制**。许多时候，允许 RAII 对象复制并不合理，如果是，那么应该禁止之。条款6给出了方法。

- **对底层资源使用“引用计数”**。有时候我们希望保有资源，直到它的最后一个使用者被销毁。 shared_ptr 就是如此。可以用 shared_ptr 管理这种资源。并提供删除器，在析构时候自动删除资源。

- **复制底部资源**。有时候，只要你喜欢，可以针对一份资源拥有其任意数量的副本。这种情况下，复制执行的是“深度拷贝”，比如标准字符串类型。

- **转移底部资源的拥有权**。比如 auto_ptr 。

!!!tip "请记住"
	- 复制 RAII 对象必须一并复制它所管理的资源，所以资源的 copying 行为决定 RAII 对象的 copying 行为。
	- 常见的 RAII class copying 行为是：抑制 copying 、施行引用计数法（ reference counting ）。