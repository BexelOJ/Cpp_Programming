#include <iostream>
#include <bitset>
#include <cstdint>

int main() {
    uint16_t x = 0x8000; // Binary: 1000 0000 0000 0001
    uint16_t result = 0;

    for (int i = 0; i < 16; ++i) {
        if (x & (1 << i)) {
            result |= (1 << (15 - i));
        }
    }

    std::cout << "Original (hex): 0x" << std::hex << x << std::endl;
    std::cout << "Original (bin): " << std::bitset<16>(x) << std::endl;
    std::cout << "Mirrored (hex): 0x" << std::hex << result << std::endl;
    std::cout << "Mirrored (bin): " << std::bitset<16>(result) << std::endl;

    return 0;
}
