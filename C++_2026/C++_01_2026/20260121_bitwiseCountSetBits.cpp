// Count Number of set Bits, using Brian Kernighan's Algorithm
#include <iostream>

int main() {
    int n = 0;
    int count = 0;

    std::cout << "Enter a Number : " << std::endl;
    std::cin >> n;
    
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    
    std::cout << "Number of Set Bits : " << count << std::endl;
    return 0;
}


