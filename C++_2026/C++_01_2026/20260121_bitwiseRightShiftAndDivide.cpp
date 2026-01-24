// Divide input by 2^pos
#include <iostream>

int main() {
    int n = 0;
    int pos = 0;

    std::cout << "Enter a Number : " << std::endl;
    std::cin >> n;

    std::cout << "Enter the position : " << std::endl;
    std::cin >> pos;

    n = n >> pos;  // divide by 2^1
    
    std::cout << "After Right Shift (Divide) : " << n << std::endl;
    
    return 0;
}


