#include <iostream>

using namespace std;

class Employee {
protected:
    int a;  // non-static member function
    static int b; // static member function
public:
    Employee(int v1 = 0) : a(v1) {
        std::cout << "Construtor Called " << std::endl;
    }

    ~Employee() {
        std::cout << "Destructor Called " << std::endl;
    }

    void display_NonStatic() {
        std::cout << "a = " << a << std::endl;
    }

    static void display_Static() {
        std::cout << "b = " << b << std::endl;
    }

};

class Cashier : public Employee {
    int c;  // non-static member function
    static int d;  // static member function
public:
    Cashier(int v1 = 0) :c(v1) {
    
    }

    ~Cashier() {
        std::cout << "Destructor Called " << std::endl;
    }

    void display_NonStatic() {
        std::cout << "a from Employee = " << a << std::endl;
        std::cout << "b from Employee = " << b << std::endl;
        std::cout << "c from cashier = " << c << std::endl;
        std::cout << "d from cashier = " << d << std::endl;
    }

    static void display_Static() {
         std::cout << "b from Employee = " << b << std::endl;
         std::cout << "d from Cashier  = " << d << std::endl;
     }

};

int Employee::b = 20;
int Cashier::d = 70;

int main() {
    Employee e1(10);
    Cashier c1(60);

    e1.display_NonStatic();
    e1.display_Static();
    c1.display_NonStatic();
    c1.display_Static();

    std::cout << "static = " << Employee::b << std::endl;
    std::cout << "static = " << Cashier::d << std::endl;

    return 0;
}


