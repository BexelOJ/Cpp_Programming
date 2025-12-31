#include <iostream>

using namespace std;

class Base {
    int a = 1;
    int b = 2;
public:
    virtual void display() {
        std::cout<<"a = "<<a <<" b = "<< b << std::endl;
    }
};

class Derived: public Base {
    int c = 3;
    int d = 4;
public:
    void display() {
        std::cout << "c = " << c << " d = " << d << std::endl;
    }
};

int main() {
    Base* b1 = new Base();
    b1->display();

    Base* b2 = new Derived();
    b2->display();

    return 0;
}



