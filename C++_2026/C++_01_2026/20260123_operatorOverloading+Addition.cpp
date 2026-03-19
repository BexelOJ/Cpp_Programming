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
    Complex operator+(const Complex& other) const {
        Complex temp = *this;
        temp.real = temp.real + other.real;
        temp.imag = temp.imag + other.imag;
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

    // += modifies z1 directly
    z1 += z2;           // z1 becomes 4 + 6i
    z1.print();         // 4 + 6i
    // z2 unchanged: 1 + 2i

    // + creates NEW result
    z3 = z1 + z2;       // z3 = 5 + 8i, z1/z2 unchanged
    z3.print();         // 5 + 8i
}


