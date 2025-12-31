#include <iostream>

int main() {
    int a = 10;
    int& ref = a;
    
    std::cout << "a = " << a << std::endl;
    std::cout << " ref = " << ref << std::endl;

    return 0;
}

