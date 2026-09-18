#include <iostream>

unsigned int evenOrOdd(unsigned int n) {
    bool res = n & 1;
    return res;
}

int main() {
    int n = 0;

    std::cout << "Enter a Number : " << std::endl;
    std::cin >> n;

    //int res = evenOrOdd(n);
    if (evenOrOdd(n)) {
        std::cout << "Odd Number" << std::endl;
    }
    else {
        std::cout << "Even Number" << std::endl;
    }

    return 0;
}


