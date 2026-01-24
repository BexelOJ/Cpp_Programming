#include <iostream>
#include <iomanip>
#include <cstdint>

uint8_t swap(uint8_t x);
//uint8_t swap_bits(uint8_t x, int p1, int p2);

int main() {
    int a = 0x00;
    std::cout << "Enter and Integer number: " << std::endl;
    std::cin >> a;

    std::cout << "Before Swap (dec) : " << static_cast<int>(a) << std::endl;
    std::cout << "Before Swap (hex) : " << std::hex << std::uppercase << "0x" << static_cast<int>(a) << std::endl;

    uint8_t res = swap(a);
    std::cout << "After Swap (dec) : " << static_cast<int>(res) << std::endl;
    std::cout << "After Swap (hex) : " << std::hex << std::uppercase << "0x" << static_cast<int>(res) << std::endl;

    return 0;
}

uint8_t swap(uint8_t x) {
    uint8_t res = x;
    res = (((res & 0x03) << 6) | ((res & 0xC0) >> 6) | (res & 0x3C));

    return res;
}

