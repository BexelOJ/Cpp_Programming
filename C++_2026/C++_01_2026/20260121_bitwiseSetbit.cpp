// set bit at position pos
#include <iostream>

int main() {
    
    int n = 0;
    int pos = 0;

    std::cout << "Enter the Number, and position to set the bit" << std::endl;
    
    std::cin >> n >> pos;
    int dup = n;
    
    std::cout << "Number = " << n << " Position = " << pos << std::endl;
    n = n | (1 << pos);
    
    std::cout << "Final Result after Setting : " << n << std::endl;

    
    dup = dup & ~(1 << pos);
    
    std::cout << "Final Result after Clearing : " << dup << std::endl;

    return 0;
}


