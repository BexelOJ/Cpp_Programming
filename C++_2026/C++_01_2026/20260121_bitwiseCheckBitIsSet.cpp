// Check if a bit at position pos is set or not
#include <iostream>

int main() {
    int n = 0;
    int pos = 0;

    std::cout << "Enter the Number, and position to check the bit" << std::endl;
    std::cin >> n >> pos;

    if (n & (1 << pos)) {
        std::cout << "Bit is Set at position " << pos << std::endl;
    }
    else {
        std::cout << "Bit is not Set at position " << pos << std::endl;
    }

    return 0;
}


