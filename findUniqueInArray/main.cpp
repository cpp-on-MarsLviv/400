#include <vector>
#include <map>
#include <iostream>

template<typename T>
void findUnique(T* arr, size_t size) {
    std::map<T, size_t> map;
    for (int i = 0; i < size; ++i) {
    	if ( map.find(arr[i]) == map.end() ) {
  		map[arr[i]] = 1;
	} else {
  		int count = map[arr[i]];
  		map[arr[i]] = ++count;
	}
    }
    for (auto it=map.begin(); it!=map.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
}

int main(){
    std::cout << "find unique" << std::endl;
    
    int * arr = new int[10];
    arr[0] = 5; arr[1] = 6; arr[2] = 5; arr[3] = 6; arr[4] = 1; 
    arr[5] = 5; arr[6] = 2; arr[7] = 5; arr[8] = 6; arr[9] = 5; 
    
    findUnique<int>(arr, 10);
    
    // not works until C++20
    /*
    std::vector myvector{3, 1, 2, 9, 4, 8, 7, 5, 6}; 
    auto greater_than_five = [](int i) { return i > 5; };
    auto next_number = [](int i) { return i + 1; };
    auto filtered = myvector | 
    std::ranges::views::filter(greater_than_five) |
    std::views::transform(next_number);*/
}
