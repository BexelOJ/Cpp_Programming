#include <iostream>

int bitwiseAdd(int a, int b) {
    while (b != 0) {
        int carry = (a & b) << 1;  // bits to carry over
        std::cout<<"a="<<a<<" b="<<b<<" c="<<carry<<std::endl;
        a = a ^ b;                 // sum without carry
        b = carry;                 // update b to carry
    }
    return a;
}

int main() {
    int x = 13;   // binary: 1101
    int y = 6;    // binary: 0110

    std::cout << "Sum: " << bitwiseAdd(x, y)<< std::endl;
    return 0;
}

