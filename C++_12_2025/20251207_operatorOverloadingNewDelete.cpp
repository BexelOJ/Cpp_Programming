#include <iostream>
#include <cstdlib>
#include <cstddef>

using namespace std;

void* operator new(size_t size) {
    // std::cout << "Size: " << size <<std::endl;
    std::cout << "Global new: allocating " << size << " bytes" << std::endl;
    void* ptr = malloc(size);
    return ptr;
}

void operator delete(void* ptr) {
    std::cout << "Global delete" << std::endl;
    free(ptr);
}

int main() {
    int* arr = new int[5];
    
    for (int i = 0; i < 5; ++i) {
        arr[i] = i;
    }
    
    delete[] arr;
    
    return 0;
}


