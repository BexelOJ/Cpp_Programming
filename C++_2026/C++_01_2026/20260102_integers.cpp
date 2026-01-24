#include <iostream>

using namespace std;

int main() {
    short int a = 10;
    int b = 20;
    long int c = 30;
    long long int d = 40;

    double dob = 60;
    long double lob = 70;

    std::cout << "Short Int size : " << sizeof(a) << std::endl;
    std::cout << "Int size : " << sizeof(b) << std::endl;
    std::cout << "Long Int size : " << sizeof(c) << std::endl;
    std::cout << "Long long Int size : " << sizeof(d) << std::endl;
    std::cout << "Double size : " << sizeof(dob) << std::endl;
    std::cout << "Long Double size : " << sizeof(lob) << std::endl;
    std::cout << "Short double size : " << sizeof(shb) << std::endl;

    return 0;
}


