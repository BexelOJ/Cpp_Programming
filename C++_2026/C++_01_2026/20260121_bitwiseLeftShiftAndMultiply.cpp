// Multiply input by 2^pos
#include <iostream>

int main() {
    int n = 0;
    int pos = 0;

    std::cout << "Enter a Number : " << std::endl;
    std::cin >> n;
    
    std::cout << "Enter the Position Count " << std::endl;
    std::cin >> pos;
    
    n = n << pos; // multiply by 2^1
    
    std::cout << "After Left Shift (Multiply) : " << n << std::endl;
    
    return 0;
}


