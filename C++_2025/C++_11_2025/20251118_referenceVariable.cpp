#include <iostream>
#include <string>

using namespace std;

int main() {

    int x = 10;

    void* ptr_1 = 0;
    void* ptr_2 = nullptr;
    int* ptr_3 = &x;

    int& refx_1 = x;
    int*& refx_2 = ptr_3;

    std::cout << "x      = " << x << std::endl;
    std::cout << "refx_1 = " << refx_1 << std::endl;

    // x =10
    refx_1++;
    // x = 11

    std::cout << "x      = " << x << std::endl;
    std::cout << "refx_1 = " << refx_1 << std::endl;
    
    std::cout << "ptr_1  = " << ptr_1 << std::endl;
    std::cout << "ptr_2  = " << ptr_2 << std::endl;

    std::cout << "ptr_3   = " << ptr_3 << std::endl;
    std::cout << "*ptr_3  = " << *ptr_3 << std::endl;
    std::cout << "refx_2  = " << refx_2 << std::endl;
    std::cout << "*refx_2 = " << *refx_2 << std::endl;

    std::cout << sizeof(ptr_1) << std::endl;
    std::cout << sizeof(ptr_2) << std::endl;
    std::cout << sizeof(void*) << std::endl;

    return 0;
}



