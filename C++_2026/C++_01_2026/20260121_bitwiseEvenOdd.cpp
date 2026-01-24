// To chekc if the integer number is Even or Odd
#include <iostream>

int main() {
    int  n = 0;
    
    std::cout << "Enter a Number: " << std::endl;
    std::cin >> n;
    
    if (n & 1) {
        std::cout << n << " is Odd" << std::endl;
    }
    else {
        std::cout << n << " is Even" << std::endl;
    }
    
    return 0;
}


