#include <iostream>
#include <algorithm>

using namespace std;
class Base {
protected:
    int a;
    int b;
public:
    Base(int val_1, int val_2) :a(val_1), b(val_2) {
        std::cout << "Base Construtor called" << std::endl;
    }
    
    virtual void display() {
        std::cout << "Printing something" << std::endl;
    }

    virtual void display_two() {
        std::cout << "Printing something in second fn" << std::endl;
    }
    
    void display_three() {
        std::cout << "Printing something in third fn" << std::endl;
    }
    
    ~Base() {
        std::cout << "Base Destructor called" << std::endl;
    }
    
};

class Derived : public Base {
    int c;
    int d;
public:
    
    Derived(int base_a, int base_b, int val_1, int val_2) :Base(base_a, base_b),c(val_1), d(val_2) {
        std::cout << "Derived Construtor called" << std::endl;
    }
    
    Derived(int val_1, int val_2):Base(1,2),c(val_1), d(val_2) {
        std::cout << "Derived Construtor called" << std::endl;
    }
    
    void display() {
        std::cout << "Printing something" << std::endl;
    }
    
    void display_two() {
        std::cout << "Printing something in second fn" << std::endl;
    }
    
    virtual void display_three() {
        std::cout << "Printing something in third fn" << std::endl;
    }
    
    ~Derived() {
        std::cout << "Derived Destrutor called" << std::endl;
    }
};

int main() {
    Base *b1 = new Base(10,20);
    Derived *d1 = new Derived(30,40);
    std::cout << "Size of Base Object: " << sizeof(*b1)<<std::endl;
    std::cout << "Size of Derived Object: " << sizeof(*d1)<<std::endl;
    
    //b1->display();

    delete b1;
    delete d1;

    return 0;
}


