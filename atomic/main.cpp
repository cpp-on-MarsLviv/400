#include "atomic.h"

#include <iostream>

int main(){
    std::cout << "custom Atomic class" << std::endl;
    
    Atomic<double> double0;
    std::cout << "init default double:" << double0.load() << std::endl;
    
    try {
	Atomic<uint> uint0;
	std::cout << "init default uint:" << uint0.load() << std::endl;
    } catch (const std::invalid_argument& ia) {
    	std::cerr << "Invalid argument: " << ia.what() << '\n';
    }
	    
    
    Atomic<int> int1 (10);
    std::cout << "init int1:" << int1.load() << std::endl;
    
    int1.store(20);
    std::cout << "load 20:" << int1.load() << std::endl;
    
    Atomic<int> int2 = int1;
    int2.store(30);
    
    int1 = int2;
    std::cout << "init int1 again:" << int1.load() << std::endl;
    
    return 0;
}
