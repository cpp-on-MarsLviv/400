#include <iostream>

template <typename T>
Vector<T>::Vector() : mySize(0), myCapacity(DEFAULT_CAPACITY) {
    	data = new T[DEFAULT_CAPACITY];
}

template <typename T>
Vector<T>::Vector(size_t initCapacity) : mySize(0), myCapacity(initCapacity) {
    	data = new T[initCapacity];
}

template <typename T>
Vector<T>::~Vector() {
    	delete[] data;
}

template <typename T>
size_t Vector<T>::size() const {
	return mySize;
};

template <typename T>
void Vector<T>::clear() {
	delete[] data;
	data = 0;
	mySize = 0;
};

template <typename T>
void Vector<T>::pop_back() {
	--mySize;
};

template <typename T>
void Vector<T>::push_back(T item) {
	
	ensure_capacity();
	data[mySize++] = item;
};

template <typename T>
void Vector<T>::pop_front() {
	
	for (int i = 0; i < mySize; ++i)
		data[i] = data[i + 1];
	--mySize;
};

template <typename T>
void Vector<T>::push_front(T item) {
	
	ensure_capacity();
	for (int i = mySize; i > 0; --i)
		data[i] = data[i - 1];
	data[0] = item;
	++mySize;
};

template <typename T>
void Vector<T>::ensure_capacity() {
	
	if (mySize == myCapacity) {
		int newCapacity = myCapacity + DEFAULT_CAPACITY;
		T * tmp = new T[newCapacity];
		for (int i = 0; i < mySize; ++i)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
		myCapacity = newCapacity;
	}
};

template <typename T>
T& Vector<T>::operator[](size_t const number) {
	return data[number];
};

template <typename T>
T Vector<T>::operator[](size_t const number) const {
	return data[number];
};



