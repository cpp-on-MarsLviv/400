#include <iostream>
#include <set>

using std::cout;
using std::endl;

template<typename T>
linked_list<T>::linked_list() {
    	cout << "linked_list::linked_list" << endl;
    	data = new T();
}

template<typename T>
linked_list<T>::linked_list(T * _data) : data(_data) {
    	cout << "linked_list::linked_list with " << *_data << endl;
}

template<typename T>
linked_list<T>::~linked_list() {
    	cout << "linked_list::~linked_list" << endl;
    	delete data;
}

template<typename T>
T * linked_list<T>::getData() const {
	return data;
}

template<typename T>
linked_list<T> * linked_list<T>::getNext() const {
	return next;
}

template<typename T>
size_t linked_list<T>::getSize() const {
	size_t size = 1;
	const linked_list * curr = this;
	while (curr->getNext()) {
		++size;
		curr = curr->getNext();
	}
	
	return size;
}

template<typename T>
void linked_list<T>::setData(T * data) {
	this->data = data;
}

template<typename T>
void linked_list<T>::push_back(linked_list * item) {
	cout << "linked_list::push_back" << endl;
	this->next = item;
}

template<typename T>
linked_list<T> * linked_list<T>::reversed(linked_list<T> * list) {
	
	linked_list<T> * tail = new linked_list<T>(list->getData());
	linked_list<T> * curr = list;
	
	while (curr->getNext()) {
		linked_list<T> * new_list = new linked_list<T>(curr->getNext()->getData());
		new_list->push_back(tail);
		tail = new_list;
		curr = curr->getNext();
	}
	
	return tail;
}

template<typename T>
bool linked_list<T>::insert(linked_list<T> * list, linked_list<T> * element, linked_list<T> * new_item) {

	linked_list<T> * curr = list;
	
	while(curr) {
		if (curr == element) {
			linked_list<T> * next = curr->getNext();
			curr->push_back(new_item);
			curr->getNext()->push_back(next);
			return true;
		}
		curr = curr->getNext();
	}
	
	return false;
}

template<typename T>
bool linked_list<T>::insert(linked_list<T> * list, int const index, linked_list<T> * new_item) {
	if (index < 1) return false;
	
	size_t curr_index = 0;
	linked_list<T> * curr = list;
	while (curr->getNext()) {
		if (++curr_index == index) {
			linked_list<T> * next = curr->getNext();
			curr->push_back(new_item);
			curr->getNext()->push_back(next);
			return true;
		}
		curr = curr->getNext();
	}
	
	return false;
}

template<typename T>
bool linked_list<T>::isCycled(const linked_list<T> * list) {
	const linked_list<T> * curr = list;
	std::set<const linked_list<T> *> items;
	items.insert(curr);
	
	while (curr->getNext()) {
		curr = curr->getNext();
		auto pair = items.insert(curr);
		
		if (!pair.second) 
			return true;
	} 
	return false;
}

template<typename T>
void linked_list<T>::print(const linked_list<T> * list) {
	const linked_list<T> * curr = list;
	while(curr) {
		cout << "data:" << *curr->getData() << endl;
		curr = curr->getNext();
	}

}

