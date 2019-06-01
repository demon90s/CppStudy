#ifndef BLOB_PTR_H
#define BLOB_PTR_H

template<typename> class Blob;

// 若试图访问一个不存在的元素，BlobPtr抛出一个异常
template<typename T> class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T> &a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr]; // (*p)为指向本对象的vector
	}

	BlobPtr& operator++();
	BlobPtr& operator--();

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;

	// 保存一个weak_ptr, 表示底层vector可能被销毁
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;	// 数组中的当前位置
};

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
	{
		throw std::runtime_error("unbound BlobPtr");
	}

	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

#endif
