#include <iostream>

void func3(){
    std::cout << "Inside Function 03" <<std::endl;
    int *ptr = nullptr;
    *ptr = 100;        // Segmentation Fault
}

void func2(){
    std::cout << "Inside Function 02" <<std::endl;
    func3();
}

void func1(){
    std::cout << "Inside Function 01" <<std::endl;
    func2();
}

int main(){
    std::cout << "Program started\n";

    func1();

    std::cout << "Program ended\n";

    return 0;
}
