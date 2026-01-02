#include <iostream>
#include <cstddef> // for std::size_t

struct alignas(16) AlignedData {
    char data[16];
};

int main() {
    AlignedData d;

    std::cout << "Alignment of int: " << alignof(int) << std::endl;
    std::cout << "Alignment of AlignedData: " << alignof(AlignedData) << std::endl;
    std::cout << "Address of d: " << &d << std::endl;

    return 0;
}

