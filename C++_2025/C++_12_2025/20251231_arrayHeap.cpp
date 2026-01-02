#include <iostream>


int main() {
    int* ptr = new int[4] {2, 4, 6, 8};
    std::cout << *ptr << std::endl;
    int* ptr_2 = nullptr;
    ptr_2 = ptr;
    std::cout << *(ptr_2 + 1) << std::endl;

    delete[] ptr;
    ptr = nullptr;
    ptr_2 = nullptr;
   
    return 0;
}

