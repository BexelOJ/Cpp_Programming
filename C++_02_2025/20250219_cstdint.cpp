#include <iostream>
#include <cstdint>  // Required for fixed-width integer types

int main() {
    uint8_t small = 255;        // 8-bit unsigned integer
    int32_t large = -2147483647; // 32-bit signed integer

    std::cout << "uint8_t value: " << (int)small << std::endl;
    std::cout << "int32_t value: " << large << std::endl;
    std::cout << "int32_t value: " << (int)large << std::endl;

    return 0;
}

