#include <iostream>
#include <string>
#include <typeinfo>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
Atomic<T>::Atomic() {
    	cout << "Atomic::Atomic()" << endl;
    	if (!supportedType())
    		throw std::invalid_argument(std::string(typeid(T).name()) + " type is not supported."); 
    	
    	item = T();
}

template <typename T>
Atomic<T>::Atomic(T newItem) {
    	cout << "Atomic::Atomic(T)" << endl;
    	if (!supportedType())
    		throw std::invalid_argument(std::string(typeid(T).name()) + " type is not supported.");
    	
    	item = newItem; 
}

template <typename T>
Atomic<T>::~Atomic() {
    	cout << "Atomic::~Atomic" << endl;
}

template <typename T>
Atomic<T>::Atomic(const Atomic<T> & newItem) {
    	cout << "Atomic(const Atomic<T> &)" << endl;
    	
    	item = newItem.load();
}

template <typename T>
Atomic<T>& Atomic<T>::operator=(const Atomic<T> & other) {
    	cout << "operator=(const Atomic<T> & other)" << endl;
    	if (this == &other)
        	return *this;
    	
    	item = other.load();
    	
    	return *this;
}

template <typename T>
T Atomic<T>::load() const noexcept {
	std::lock_guard<std::mutex> guard(mutex);
	T temp = item;
	return temp;
};

template <typename T>
void Atomic<T>::store(T newValue) noexcept {
	std::lock_guard<std::mutex> guard(mutex);
	item = newValue;
};

template <typename T>
bool Atomic<T>::supportedType() {
	
	return typeid(T).name() == typeid(bool).name() ||
		typeid(T).name() == typeid(char).name() ||
		typeid(T).name() == typeid(int).name() ||
		typeid(T).name() == typeid(long).name() ||
		typeid(T).name() == typeid(float).name() ||
		typeid(T).name() == typeid(double).name();
}



