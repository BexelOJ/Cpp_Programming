#include <iostream>

void printBinary(int num) {
    for (int i = 31; i >= 0; --i) {
        std::cout << ((num >> i) & 1);
        if (i % 4 == 0) std::cout << ' ';  // optional: group by 4 bits
    }
    std::cout << std::endl;
}

int main() {
    int num = 23;
    std::cout << "Binary: ";
    printBinary(num);
    return 0;
}

