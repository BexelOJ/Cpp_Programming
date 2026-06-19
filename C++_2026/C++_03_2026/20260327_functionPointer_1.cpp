#include <iostream>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    return a / b;
}

int main() {
    int (*fnPtr[])(int, int) = {add, sub, mul, divi};
    
    std::cout << fnPtr[0](15, 2)<<std::endl;
    std::cout << fnPtr[1](15, 2) << std::endl;
    std::cout << fnPtr[2](15, 2) << std::endl;
    std::cout << fnPtr[3](15, 2) << std::endl;
    return 0;
}


