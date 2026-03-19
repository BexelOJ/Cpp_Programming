#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator*(const Complex& other) const {
        double new_real = (real * other.real) - (imag * other.imag);
        double new_imag = (real * other.imag) + (imag * other.real);
        return Complex(new_real, new_imag);
    }

    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};


int main() {
    Complex z1(3, 4);   // 3 + 4i
    Complex z2(1, 2);   // 1 + 2i
    Complex z3;

    // - creates NEW result
    z3 = z1 * z2;
    z3.print();
}


/*
OUTPUT:

-5 + 10i

*/


