#include <iostream>
#include <bitset>

int main(){
    std::bitset<8> b = 0b10101010; // Example bitset
    std::cout << "Original bitset: " << b << std::endl;
    std::cout << "Size of bitset: " << b.size() << std::endl;
    std::cout << "Count of set bits: " << b.count() << std::endl;
    std::cout << "Any bit set? " << (b.any() ? "True" : "False") << std::endl;
    std::cout << "All bits set? " << (b.all() ? "Yes" : "No") << std::endl;
    std::cout << "None bits set? " << (b.none() ? "Yes" : "No") << std::endl;    
    std::cout << "Bit at position 2: " << b[2] << std::endl;
    std::cout << "Bit at position 3: " << b.test(3) << std::endl;
    std::cout << "Bit at position 4: " << b[4] << std::endl;

std::cout << "Complement: " << ~b	 << std::endl;

    return 0;
}

