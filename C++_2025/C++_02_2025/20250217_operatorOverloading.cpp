#include <iostream>
using namespace std;

class Complex 
{
public:
    double real;
    double imag;

public:
    // Constructor to initialize the complex number
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the '+' operator to add two Complex numbers
    Complex operator+(const Complex& other) 
    {
        // Return a new Complex number with added real and imaginary parts
        return Complex(real + other.real, imag + other.imag);
    }

    // Function to display the complex number
    void display() const {    
        cout << real << " + " << imag << "i" << endl;
    }
    //friend()
};

int main() 
{
    Complex a;
    cout<<"Enter Real and Imaginary parts of the Complex Number 1: "<<endl;
    cin>>a.real>>a.imag;
    Complex c1(a.real, a.imag);  // First complex number: 3 + 4i
    cout<<"Enter Real and Imaginary parts of the Complex Number 2: "<<endl;
    cin>>a.real>>a.imag;
    Complex c2(a.real, a.imag);  // Second complex number: 1 + 2i

    // Add the two complex numbers using the overloaded '+' operator
    Complex result = c1 + c2;  // Uses operator+()

    // Display the result
    result.display();  // Output: 4 + 6i

    return 0;
}


