#include <iostream>
#include <algorithm>

using namespace std;

class Base {
    int a;

public:
    //int* ptr;
    Base(int val=0):a(val) {
        std::cout << "Parameterized Construtor called" << std::endl;
    }

    // Copy Construtor
    Base(const Base& other) {
        a = other.a;
        std::cout << "Copy Construtor Called" << std::endl;
    }

    // Copy Assignment Operator
    Base& operator=(const Base& other) {
        if (this != &other) {
            a = other.a;
            std::cout<<"Copy Assignment Operator Called"<<std::endl;
        }
        return *this;
    }
    
    int display() {
        //std::cout << a << std::endl;
        return a;
    }

    ~Base() {
        std::cout << "Destrutor called" << std::endl;
    }
};

int main() {
    Base b1(10);  // Parameterized Construtor called
    Base* b2ptr = new Base(20);  // Parameterized Construtor called

    int* ptr = new int[5];

    Base b3 = b1;    // copy construtor called, copy initialization
    // Base b4(b1);  // copy construtor called, direct initialization
    Base b5;      // default construtor called
    b5 = *b2ptr;  // copy assignemnt operator called

    //Base b6;
    //b6(b1);

    std::cout << b1.display() << std::endl;
    std::cout << b2ptr->display() << std::endl;
    
    std::cout << b3.display() << std::endl;
    std::cout << b5.display() << std::endl;

    delete b2ptr;
    delete[] ptr;  // deleting an array
    return 0;
}


/*
Output:

Parameterized Construtor called
Parameterized Construtor called
Copy Construtor Called
Default Construtor called
Copy Assignment Operator Called
10
20
10
20
Destrutor called
Destrutor called
Destrutor called
Destrutor called

*/
