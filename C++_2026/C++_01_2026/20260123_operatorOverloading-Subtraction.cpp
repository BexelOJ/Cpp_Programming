#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // += modifies THIS object
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // + creates NEW object
    Complex operator-(const Complex& other) const {
        Complex temp = *this;
        temp.real = temp.real - other.real;
        temp.imag = temp.imag - other.imag;
        return Complex(temp.real, temp.imag);
    }

    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};


int main() {
    Complex z1(3, 4);   // 3 + 4i
    Complex z2(1, 2);   // 1 + 2i
    Complex z3;
    Complex z4;

    // - creates NEW result
    z3 = z1 - z2;      
    z3.print();

    z2 += z1;
    z2.print();
}


/*
OUTPUT:

2 + 2i

4 + 6i

*/

