#include <iostream>



int main(){
    std::cout << "double deletion is OK when pointer is nullptr" << std::endl;
    
    int * arr = new int[10];
    for (auto i = 0; i < 10; ++i)
    	arr[i] = 44;
    
    int * val = new int();
    *val = 60;
    
    delete val;
    val = nullptr;
    delete val;
    
    delete[] arr;
    arr = nullptr;
    delete[] arr;
    
    return 0;
}
