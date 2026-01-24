// Clear a bit at position pos
#include <iostream>

int main() {
    int n = 0;
    int pos = 0;
    int dup = 0;

    std::cout << "Enter a Number : " << std::endl;
    std::cin >> n;
    dup = n;

    std::cout << "Enter the position : " << std::endl;
    std::cin >> pos;
    
    n = n & ~(1 << pos);

    std::cout << "Final Result after Clearing : " << n << std::endl;

    dup = dup | (1 << pos);
    std::cout << "Final Result after Setting : " << dup << std::endl;

    return 0;
}


