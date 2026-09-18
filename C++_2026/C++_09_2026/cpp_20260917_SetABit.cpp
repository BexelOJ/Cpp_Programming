#include <iostream>

unsigned int setBit(unsigned int n, int pos) {
    unsigned int num = (n | (1 << pos));
    return num;
}


int main() {
    int n = 0, pos = 0;
    std::cout << "Enter the Number and Position of the bit:" << std::endl;
    std::cin >> n >> pos;

    unsigned int res = setBit(n, pos);
    std::cout << res << std::endl;

    return 0;
}



