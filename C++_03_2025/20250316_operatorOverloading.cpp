#include <iostream>

using namespace std;

class Complex {
public:
    int a;
    int b;

    Complex(int x, int y) : a(x), b(y)
    {
        cout << "CC Called" << endl;
    }

    Complex add(const Complex& other)
    {
        Complex bas(0, 0);
        bas.a = a + other.a;
        bas.b = b + other.b;
        return bas;
    }

    Complex operator+(const Complex& other)
    {
        Complex bas(0, 0);
        bas.a = a + other.a;
        bas.b = b + other.b;
        return bas;
    }

    void display()
    {
        cout << a << " + i" << b << endl;
    }


};

int main()
{
    Complex c1(1, 3);
    Complex c2(4, 5);
    Complex c3 = c1 .operator+ (c2);
    Complex c5 = c1 + c2;
    Complex c4 = c1.add(c2);
    c3.display();
    c4.display();
    c5.display();
    return 0;
}

