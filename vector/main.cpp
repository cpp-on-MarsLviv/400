#include "vector.h"

#include <iostream>

class A { 
	int a = 7; 
public:
	friend std::ostream& operator << (std::ostream& os, const A& obj){
		os << obj.a << ' ';
		return os ;
	}
};

int main(){
    std::cout << "container Vector realization" << std::endl;
    
    Vector<int> vector;
    Vector<int> vector2(2);
    
    vector.push_back(17);
    vector.push_back(217);
    std::cout << "vector::size:" << vector.size() << std::endl;
    vector.pop_back();
    std::cout << "vector::size:" << vector.size() << std::endl;
    
    vector2.push_back(17);
    vector2.push_back(217);
    vector2.push_back(17);
    vector2.push_back(217);
    std::cout << "vector2::size:" << vector2.size() << std::endl;
    
    std::cout << "vector2:" 	<< vector2[0] << " " 
    				<< vector2[1] << " "
    				<< vector2[2] << " "
    				<< vector2[3] << std::endl;
    	
    int & ref = vector2[1];
    ref = 1000;
    int var = vector2[0];
    var = 1000;
    std::cout << "vector2:" 	<< vector2[0] << " " 
    				<< vector2[1] << " "
    				<< vector2[2] << " "
    				<< vector2[3] << std::endl;
    				
    vector2.clear();
    std::cout << "vector2::size:" << vector2.size() << std::endl;
    
    
    A a1, a2, a3;
    Vector<A> vector3(2);
    vector3.push_back(a1);
    vector3.push_back(a2);
    vector3.push_back(a3);
    std::cout << "vector3:" 	<< vector3[0] << " " 
    				<< vector3[1] << " "
    				<< vector3[2] << std::endl;
    vector3.clear();
    std::cout << "vector3::size():" << vector3.size() << std::endl;
    
    return 0;
}
