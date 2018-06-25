#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

class Delete
{
public:
	template<typename T> void operator()(T *p) const { delete p; }
};

template<typename T, typename D = Delete>
class UniquePtr
{
public:
	UniquePtr(T *p = nullptr, const D &d = D()) : m_p(p), m_del(d) {}
	~UniquePtr()
	{
		if (m_p) {
			m_del(m_p);
		}
	}
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	T& operator*() const { return *m_p; }
	T* operator->() const { return &this->operator*(); }

private:
	T *m_p = nullptr;
	D m_del;
};

#endif
