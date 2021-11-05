#pragma once

#include <cstddef>

template<typename T>
class Vector {
	size_t const DEFAULT_CAPACITY = 16;
	
	T * data;

	size_t mySize;
	size_t myCapacity;

public:
	Vector();
	Vector(size_t initCapacity);
	
	~Vector();
	
	T& operator[](size_t const number);
	T operator[](size_t const number) const;
	
	size_t size() const;
	void clear();
	
	void push_back(T item);
	void pop_back();
	
	void push_front(T item);
	void pop_front();
private:
	void ensure_capacity();
};

#include "vector.cpp"
