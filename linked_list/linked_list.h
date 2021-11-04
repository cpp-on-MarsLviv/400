#pragma once

#include <cstddef>

/**
	Templated linked list
	To use custom data type overload operator <<
*/

template<typename T>
struct linked_list {
private:
	/**
	* pointer to next item in linked_list
	*/
	linked_list * next = nullptr;
	/**
	* pointer to nested data
	*/
	T * data = nullptr;

public:
	linked_list();
	linked_list(T * data);
	
	~linked_list();
	
	T * getData() const;
	linked_list * getNext() const;
	size_t getSize() const;

	void setData(T * data);
	
	/**
	* assign item to next
	* pointer to current next item will be lost
	* @param list is item of linked_list to set next
	*/
	void push_back(linked_list * item);
	
	/**
	* @param list the base linked_list
	* @return totally new reversed linked_list
	*/
	static linked_list<T> * reversed(linked_list<T> * list);
	
	/**
	* @param list the base linked_list
	* @return the same but reversed linked_list
	*/
	// TODO linked_list * reverse(linked_list * list) const;
	
	/**
	* insert new_item after element in list
	* @param list - base list
	* @param element - insertion after that element
	* @param new_item - insert this item
	* @return logical status of insertion
	*/
	static bool insert(linked_list * list, linked_list * element, linked_list * new_item);
	
	/**
	*  insert item in index place in list
	* @param list - base list
	* @param index - insertion in that index
	* @param new_item - insert this item
	* @return logical status of insertion
	*/
	static bool insert(linked_list * list, int const index, linked_list * new_item);
	
	static void print(const linked_list * list);
	
	/**
	*  check if list cycled
	* @param list - base list
	* @return true if list cycled
	*/
	static bool isCycled(const linked_list * list);
};

#include "linked_list.cpp"
