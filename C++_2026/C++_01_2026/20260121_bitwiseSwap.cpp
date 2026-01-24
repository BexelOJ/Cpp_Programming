#include <iostream>

int main() {
    int a = 0x01;
    int b = 0x04;

    std::cout << "Enter the First Number to Swap : " << std::endl;
    std::cin >> a;

    std::cout << "Enter the Second Number to Swap : " << std::endl;
    std::cin >> b;

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    std::cout << "After Swap, Value of a = " << a << std::endl;
    std::cout << "After Swap, Value of b = " << b << std::endl;

    return 0;
}



