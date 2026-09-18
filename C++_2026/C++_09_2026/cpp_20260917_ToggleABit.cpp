#include <iostream>

unsigned int toggleBit(unsigned int n, int pos) {
    unsigned int num = ( n xor (1 << pos));
        return num;
}


int main() {
    int n = 0, pos = 0;
    std::cout << "Enter the Number and Position of the bit:" << std::endl;
    std::cin >> n >> pos;

    unsigned int res = toggleBit(n, pos);
    std::cout << res << std::endl;

    return 0;
}



