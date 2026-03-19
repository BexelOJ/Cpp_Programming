#include <iostream>

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator/(const Complex& other) const {
        // (a+bi)/(c+di) = [(ac+bd)/(c²+d²)] + [(bc-ad)/(c²+d²)]i
        double denom = (other.real * other.real) + (other.imag * other.imag);

        // Avoid division by zero
        if (denom == 0) {
            throw std::runtime_error("Division by zero complex number");
        }

        double new_real = (real * other.real + imag * other.imag) / denom;
        double new_imag = (imag * other.real - real * other.imag) / denom;

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
    z3 = z1 / z2;
    z3.print();
}

/*
OUTPUT:

2.2 + -0.4i

*/

