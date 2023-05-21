#pragma once
#include <iostream>
#include <vector>

/**
 * 
 * C++ has its own implementation of iterator that works with a different
 * generics containers defined by the standard library.
 */

template<typename T, typename U>
class Iterator
{
public:
	using iter_type = typename std::vector<T>::iterator;
	Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data)
	{
		m_it_ = m_p_data_->getVector().begin();
	}

	void first()
	{
		m_it_ = m_p_data_->getVector().begin();
	}

	void Next() {
		m_it_++;
	}

	bool IsDone() {
		return (m_it_ == m_p_data_->m_data_.end());
	}

	iter_type Current() {
		return m_it_;
	}

private:
	U* m_p_data_;
	iter_type m_it_;
};

template <class T>
class Container
{
	friend class Iterator<T, Container>;
public:
	void add(T a) 
	{
		m_data_.push_back(a);
	}
	
	Iterator<T, Container>* CreateIterator()
	{
		return new Iterator<T, Container>(this);
	}

	std::vector<T>& getVector() { return m_data_; }

private:
	std::vector<T> m_data_;

};

class Data {
public:
	explicit Data(int a = 0) : m_data_(a) {}

	void set_data(int a) { m_data_ = a; }

	int data() const { return m_data_; }

private:
	int m_data_;
};