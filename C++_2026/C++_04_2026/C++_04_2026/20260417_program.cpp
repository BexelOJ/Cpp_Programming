#include <iostream>
#include "20260417_external.h"

int main(){
    std::cout << "Hello, World!" << std::endl;
    int res_1 = add(10, 20);
    int res_2 = subtraction(10, 20);
    int res_3 = multply(10, 20);
    int res_4 = division(10, 20);
    
    std::cout << "Addition: " << res_1 << std::endl;
    std::cout << "Subtraction: " << res_2 << std::endl;
    std::cout << "Multiplication: " << res_3 << std::endl;
    std::cout << "Division: " << res_4 << std::endl;

    std::cout << "External variable val: " << val << std::endl;

    return 0;
}

