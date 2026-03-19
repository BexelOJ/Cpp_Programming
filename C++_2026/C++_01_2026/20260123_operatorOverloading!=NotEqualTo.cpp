#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // != overload - returns bool
    bool operator!=(const Complex& other) const {
        bool res = (real != other.real || imag != other.imag);
        return (res);
    }
};

int main() {
    Complex z1(3, 4);    // 3 + 4i
    Complex z2(3, 4);    // 3 + 4i (same)
    Complex z3(1, 2);    // 1 + 2i (different)

    std::cout << (z1 != z2) << std::endl;  // 0 (false, equal)
    std::cout << (z1 != z3) << std::endl;  // 1 (true, different)
}


/*
OUTPUT:

0
1

*/

