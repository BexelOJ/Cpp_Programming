#include <iostream>

bool isPowerOfTwo(unsigned int n) {
    bool res = n > 0 && (n & (n - 1)) == 0;
//    bool res = n != 0 && (n & (n - 1)) == 0;
    return res;
}

int main() {
    unsigned int n = 0;

    std::cout<<"Enter a Number: "<<std::endl;
    std::cin >> n;

    std::cout << isPowerOfTwo(n) << std::endl;

    return 0;
}


