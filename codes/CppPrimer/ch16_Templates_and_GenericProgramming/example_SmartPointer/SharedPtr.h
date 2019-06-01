#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <functional>

template<typename T>
class SharedPtr
{
	using DelFunc = std::function<void(T*)>;

public:
	SharedPtr(T *p = nullptr, DelFunc del = nullptr) : m_use_count(new size_t(1)), m_p(p), m_del(del) {}
	~SharedPtr();
	SharedPtr(const SharedPtr&);
	SharedPtr& operator=(const SharedPtr&);

	T& operator*() const;
	T* operator->() const
	{ return &this->operator*(); }

private:
	size_t *m_use_count = nullptr;
	T *m_p = nullptr;

	DelFunc m_del;
};

template<typename T> inline
SharedPtr<T>::~SharedPtr()
{
	if (m_use_count && --*m_use_count == 0)
	{
		if (m_del)
			m_del(m_p);
		else
			delete m_p;
	
		delete m_use_count;
	}
}

template<typename T> inline
SharedPtr<T>::SharedPtr(const SharedPtr &s) : m_use_count(s.m_use_count), m_p(s.m_p), m_del(s.m_del)
{
	++*m_use_count;
}

template<typename T> inline
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr &s)
{
	if (this != &s)
	{
		if (m_use_count && --*m_use_count == 0)
		{
			if (m_del)
				m_del(m_p);
			else
				delete m_p;

			delete m_use_count;
		}

		m_use_count = s.m_use_count;
		++*m_use_count;
		m_p = s.m_p;
		m_del = s.m_del;
	}

	return *this;
}

template<typename T> inline
T& SharedPtr<T>::operator*() const
{
	return *m_p;
}

#endif // SHARED_PTR_H
