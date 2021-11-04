#pragma once

#include <mutex>

/**
	Support bool, char, int, long, float, double types
*/

template<typename T>
class Atomic {
	
	T item;
	mutable std::mutex mutex;

public:
	Atomic();
	Atomic(T item);
	
	~Atomic();
	
	Atomic(const Atomic<T> &);
	Atomic<T>& operator=(const Atomic<T> &);
	
	T load() const noexcept;
	void store(T newValue) noexcept;
	
private:
	bool supportedType();
	
};

#include "atomic.cpp"
