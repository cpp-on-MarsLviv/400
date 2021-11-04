#include "linked_list.h"

#include <iostream>

class A {
    int a = 7;

    friend std::ostream& operator << (std::ostream& os, const A& item) {
    	os << item.a;
    	return os;
    }
};

int main(){
    std::cout << "linked_list realization" << std::endl;
    
    linked_list<int> item0;
    linked_list<int> item1(new int(10));
    linked_list<int> item2(new int(20));
    linked_list<int> item3(new int(30));
    
    item0.push_back(&item1); 
    item1.push_back(&item2);
    item2.push_back(&item3);
    item3.push_back(new linked_list<int>(new int(40)));
    
    std::cout << "item0 data:" << *item0.getData() << std::endl;
    std::cout << "item1 data:" << *item1.getData() << std::endl;
    std::cout << "item2 data:" << *item2.getData() << std::endl;
    std::cout << "item3 data:" << *item3.getData() << std::endl;
    
    linked_list<int>::print(&item0);

    std::cout << "reversed" << std::endl;
    linked_list<int> * rev = linked_list<int>::reversed(&item0);
    linked_list<int>::print(rev);
    
    std::cout << "insertion after item1" << std::endl;
    linked_list<int>::insert(&item0, &item1, new linked_list<int>(new int(11)));
    linked_list<int>::print(&item0);
    
    std::cout << "insertion after item3" << std::endl;
    linked_list<int>::insert(&item0, &item3, new linked_list<int>(new int(31)));
    linked_list<int>::print(&item0);
    
    std::cout << "size of item 0 is:" << item0.getSize() << std::endl;
    
    std::cout << "insertion at 4-th place" << std::endl;
    linked_list<int>::insert(&item0, 4, new linked_list<int>(new int(444)));
    linked_list<int>::print(&item0);
    
    linked_list<int> itemC0;
    linked_list<int> itemC1;
    linked_list<int> itemC2;
    linked_list<int> itemC3;
    itemC0.push_back(&itemC1);
    itemC1.push_back(&itemC2);
    itemC2.push_back(&itemC3);
    std::cout << "check cycling: before:" << linked_list<int>::isCycled(&itemC0) << std::endl;
    itemC3.push_back(&itemC1);
    std::cout << "check cycling: after:" << linked_list<int>::isCycled(&itemC0) << std::endl;
    
    
    linked_list<A> itemA0(new A());
    linked_list<A> itemA1(new A());
    linked_list<A> itemA2(new A());
    
    itemA0.push_back(&itemA1);
    itemA1.push_back(&itemA2);
    linked_list<A>::print(&itemA0);
    
    return 0;
}











